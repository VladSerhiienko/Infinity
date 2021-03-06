// Scintilla source code edit control
/** @file Document.h
 ** Text document that handles notifications, DBCS, styling, words and end of line.
 **/
// Copyright 1998-2011 by Neil Hodgson <neilh@scintilla.org>
// The License.txt file describes the conditions under which this software may be distributed.

#ifndef DOCUMENT_H
#define DOCUMENT_H

#ifdef SCI_NAMESPACE
namespace Scintilla {
#endif

/**
 * A Position is a position within a document between two characters or at the beginning or end.
 * Sometimes used as a character index where it identifies the character after the position.
 */
typedef int Position;
const Position invalidPosition = -1;

/**
 * The range class represents a range of text in a document.
 * The two values are not sorted as one end may be more significant than the other
 * as is the case for the selection where the end position is the position of the caret.
 * If either position is invalidPosition then the range is invalid and most operations will fail.
 */
class Range {
public:
	Position start;
	Position end;

	Range(Position pos=0) :
		start(pos), end(pos) {
	}
	Range(Position start_, Position end_) :
		start(start_), end(end_) {
	}

	bool Valid() const {
		return (start != invalidPosition) && (end != invalidPosition);
	}

	// Is the position within the range?
	bool Contains(Position pos) const {
		if (start < end) {
			return (pos >= start && pos <= end);
		} else {
			return (pos <= start && pos >= end);
		}
	}

	// Is the character after pos within the range?
	bool ContainsCharacter(Position pos) const {
		if (start < end) {
			return (pos >= start && pos < end);
		} else {
			return (pos < start && pos >= end);
		}
	}

	bool Contains(Range other) const {
		return Contains(other.start) && Contains(other.end);
	}

	bool Overlaps(Range other) const {
		return
		Contains(other.start) ||
		Contains(other.end) ||
		other.Contains(start) ||
		other.Contains(end);
	}
};

class DocWatcher;
class DocModification;
class Document;

// This is ASCII specific but is safe with chars >= 0x80
static inline bool isspacechar(unsigned char ch) {
	return (ch == ' ') || ((ch >= 0x09) && (ch <= 0x0d));
}

static inline bool IsPunctuation(char ch) {
	return isascii(ch) && ispunct(ch);
}

static inline bool IsADigit(char ch) {
	return isascii(ch) && isdigit(ch);
}

static inline bool IsLowerCase(char ch) {
	return isascii(ch) && islower(ch);
}

static inline bool IsUpperCase(char ch) {
	return isascii(ch) && isupper(ch);
}

/**
 * Interface class for regular expression searching
 */
class RegexSearchBase {
public:
	virtual ~RegexSearchBase() {}

	virtual long FindText(Document *doc, int minPos, int maxPos, const char *s,
                        bool caseSensitive, bool word, bool wordStart, int flags, int *length) = 0;

	///@return String with the substitutions, must remain valid until the next call or destruction
	virtual const char *SubstituteByPosition(Document *doc, const char *text, int *length) = 0;
};

/// Factory function for RegexSearchBase
extern RegexSearchBase *CreateRegexSearch(CharClassify *charClassTable);

struct StyledText {
	size_t length;
	const char *text;
	bool multipleStyles;
	size_t style;
	const unsigned char *styles;
	StyledText(size_t length_, const char *text_, bool multipleStyles_, int style_, const unsigned char *styles_) :
		length(length_), text(text_), multipleStyles(multipleStyles_), style(style_), styles(styles_) {
	}
	// Return number of bytes from start to before '\n' or end of text.
	// Return 1 when start is outside text
	size_t LineLength(size_t start) const {
		size_t cur = start;
		while ((cur < length) && (text[cur] != '\n'))
			cur++;
		return cur-start;
	}
	size_t StyleAt(size_t i) const {
		return multipleStyles ? styles[i] : style;
	}
};

class HighlightDelimiter {
public:
	HighlightDelimiter() : isEnabled(false) {
		Clear();
	}

	void Clear() {
		beginFoldBlock = -1;
		endFoldBlock = -1;
		firstChangeableLineBefore = -1;
		firstChangeableLineAfter = -1;
	}

	bool NeedsDrawing(int line) {
		return isEnabled && (line <= firstChangeableLineBefore || line >= firstChangeableLineAfter);
	}

	bool IsFoldBlockHighlighted(int line) {
		return isEnabled && beginFoldBlock != -1 && beginFoldBlock <= line && line <= endFoldBlock;
	}

	bool IsHeadOfFoldBlock(int line) {
		return beginFoldBlock == line && line < endFoldBlock;
	}

	bool IsBodyOfFoldBlock(int line) {
		return beginFoldBlock != -1 && beginFoldBlock < line && line < endFoldBlock;
	}

	bool IsTailOfFoldBlock(int line) {
		return beginFoldBlock != -1 && beginFoldBlock < line && line == endFoldBlock;
	}

	int beginFoldBlock;	// Begin of current fold block
	int endFoldBlock;	// End of current fold block
	int firstChangeableLineBefore;	// First line that triggers repaint before starting line that determined current fold block
	int firstChangeableLineAfter;	// First line that triggers repaint after starting line that determined current fold block
	bool isEnabled;
};

class CaseFolder {
public:
	virtual ~CaseFolder() {
	}
	virtual size_t Fold(char *folded, size_t sizeFolded, const char *mixed, size_t lenMixed) = 0;
};

class CaseFolderTable : public CaseFolder {
protected:
	char mapping[256];
public:
	CaseFolderTable();
	virtual ~CaseFolderTable();
	virtual size_t Fold(char *folded, size_t sizeFolded, const char *mixed, size_t lenMixed);
	void SetTranslation(char ch, char chTranslation);
	void StandardASCII();
};

class Document;

class LexInterface {
protected:
	Document *pdoc;
	ILexer *instance;
	bool performingStyle;	///< Prevent reentrance
public:
	LexInterface(Document *pdoc_) : pdoc(pdoc_), instance(0), performingStyle(false) {
	}
	virtual ~LexInterface() {
	}
	void Colourise(int start, int end);
	bool UseContainerLexing() const {
		return instance == 0;
	}
};

/**
 */
class Document : PerLine, public IDocument {

public:
	/** Used to pair watcher pointer with user data. */
	class WatcherWithUserData {
	public:
		DocWatcher *watcher;
		void *userData;
		WatcherWithUserData() {
			watcher = 0;
			userData = 0;
		}
	};

	enum charClassification { ccSpace, ccNewLine, ccWord, ccPunctuation };
private:
	CharClassify charClass;
	char stylingMask;
	int endStyled;
	int styleClock;
	int enteredStyling;

	WatcherWithUserData *watchers;
	int lenWatchers;

	// ldSize is not real data - it is for dimensions and loops
	enum lineData { ldMarkers, ldLevels, ldState, ldMargin, ldAnnotation, ldSize };
	PerLine *perLineData[ldSize];

	bool matchesValid;
	RegexSearchBase *regex;

public:

	LexInterface *pli;

	int stylingBits;
	int stylingBitsMask;

	int eolMode;
	int tabInChars;
	int indentInChars;
	int actualIndentInChars;
	bool useTabs;
	bool tabIndents;
	bool backspaceUnindents;

	DecorationList decorations;

	Document();
	virtual ~Document();

	virtual void Init();
	virtual void InsertLine(int line);
	virtual void RemoveLine(int line);

	int Version() const {
		return dvOriginal;
	}

	void SetErrorStatus(int status);

	int  LineFromPosition(int pos) const;
	int  ClampPositionIntoDocument(int pos);
	bool IsCrLf(int pos);
	int  LenChar(int pos);
	bool InGoodUTF8(int pos, int &start, int &end) const;
	int  MovePositionOutsideChar(int pos, int moveDir, bool checkLineEnd=true);
	int  NextPosition(int pos, int moveDir) const;
	bool NextCharacter(int &pos, int moveDir);	// Returns true if pos changed
	int  SafeSegment(const char *text, int length, int lengthSegment);

	void ModifiedAt(int pos);

    const char * SCI_METHOD BufferPointer() { return substance.BufferPointer(); }

	int GetLineIndentation(int line);
	int GetLineIndentPosition(int line) const;
	int GetColumn(int position);
	int CountCharacters(int startPos, int endPos);
	int FindColumn(int line, int column);

	char CharAt(int position) const { return substance.ValueAt(position); }
	void GetCharRange(char *buffer, int position, int lengthRetrieve) const
    {
	    if (lengthRetrieve < 0 ||
	        position < 0       ||
	        (position + lengthRetrieve) > substance.Length())
        {
		    //Platform::DebugPrintf("Bad GetCharRange %d for %d of %d\n", position,
		    //                      lengthRetrieve, substance.Length());
		    return;
	    }
	    substance.GetRange(buffer, position, lengthRetrieve);
	}
	char StyleAt(int position) const { return style.ValueAt(position); }
	void GetStyleRange(unsigned char *buffer, int position, int lengthRetrieve) const
    {
	    if (lengthRetrieve < 0 || 
            position < 0 ||
            (position + lengthRetrieve) > style.Length())
        {
		    //Platform::DebugPrintf("Bad GetStyleRange %d for %d of %d\n", position,
		    //                      lengthRetrieve, style.Length());
		    return;
	    }
	    style.GetRange(reinterpret_cast<char *>(buffer), position, lengthRetrieve);
	}

	int  GetMark(int line);
	int  MarkerNext(int lineStart, int mask) const;
	int  AddMark(int line, int markerNum);
	void AddMarkSet(int line, int valueSet);
	void DeleteMark(int line, int markerNum);
	void DeleteMarkFromHandle(int markerHandle);
	void DeleteAllMarks(int markerNum);
	int  LineFromHandle(int markerHandle);
	int  LineStart(int line) const;
	int  LineEnd(int line) const;
	int  LineEndPosition(int position) const;
	bool IsLineEndPosition(int position) const;
	int  VCHomePosition(int position) const;

	int  SetLevel(int line, int level);
	int  GetLevel(int line) const;
	void ClearLevels();
	int  GetLastChild(int lineParent, int level=-1, int lastLine=-1);
	int  GetFoldParent(int line);
	void GetHighlightDelimiters(HighlightDelimiter &hDelimiter, int line, int lastLine);

	//void Indent(bool forwards);
	int  ExtendWordSelect(int pos, int delta, bool onlyWordCharacters=false);
	int  NextWordStart(int pos, int delta);
	int  NextWordEnd(int pos, int delta);
	int  Length() const { return substance.Length(); }
	void Allocate(int newSize)
    {
	    substance.ReAllocate(newSize);
	    style.ReAllocate(newSize);
    }
	size_t ExtractChar(int pos, char *bytes);
	bool MatchesWordOptions(bool word, bool wordStart, int pos, int length);
	long FindText(int minPos, int maxPos, const char *search, bool caseSensitive, bool word,
		bool wordStart, bool regExp, int flags, int *length, CaseFolder *pcf);
	const char *SubstituteByPosition(const char *text, int *length);
	int LinesTotal() const;

	void SetDefaultCharClasses(bool includeWordClass);
	void SetCharClasses(const unsigned char *chars, CharClassify::cc newCharClass);
	void SetStylingBits(int bits);
	void StartStyling(int position, char mask);
	bool SetStyleFor(int length, char style);
	bool SetStyles(int length, const char *styles);
	int  GetEndStyled() { return endStyled; }
	void EnsureStyledTo(int pos);
	void LexerChanged();
	int  GetStyleClock() { return styleClock; }
	void IncrementStyleClock();
	void DecorationSetCurrentIndicator(int indicator) {
		decorations.SetCurrentIndicator(indicator);
	}
	void DecorationFillRange(int position, int value, int fillLength);

	int  SetLineState(int line, int state);
	int  GetLineState(int line) const;
	int  GetMaxLineState();
	void ChangeLexerState(int start, int end);

	StyledText MarginStyledText(int line);
	void MarginSetStyle(int line, int style);
	void MarginSetStyles(int line, const unsigned char *styles);
	void MarginSetText(int line, const char *text);
	int  MarginLength(int line) const;
	void MarginClearAll();

	bool AnnotationAny() const;
	StyledText AnnotationStyledText(int line);
	void AnnotationSetText(int line, const char *text);
	void AnnotationSetStyle(int line, int style);
	void AnnotationSetStyles(int line, const unsigned char *styles);
	int  AnnotationLength(int line) const;
	int  AnnotationLines(int line) const;
	void AnnotationClearAll();

	bool AddWatcher(DocWatcher *watcher, void *userData);
	bool RemoveWatcher(DocWatcher *watcher, void *userData);
	const WatcherWithUserData *GetWatchers() const { return watchers; }
	int GetLenWatchers() const { return lenWatchers; }

	CharClassify::cc WordCharClass(unsigned char ch);
	bool IsWordPartSeparator(char ch);
	int  WordPartLeft(int pos);
	int  WordPartRight(int pos);
	int  ExtendStyleRange(int pos, int delta, bool singleLine = false);
	bool IsWhiteLine(int line) const;
	int  ParaUp(int pos);
	int  ParaDown(int pos);
	int  IndentSize() { return actualIndentInChars; }
	int  BraceMatch(int position, int maxReStyle);

	/// Actions without undo
	void InsertString(int position, const char *s, int insertLength);
	void DeleteChars(int position, int deleteLength);

private:
	bool IsWordStartAt(int pos);
	bool IsWordEndAt(int pos);
	bool IsWordAt(int start, int end);

	//void NotifyModifyAttempt();
	//void NotifySavePoint(bool atSavePoint);
	void NotifyModified(DocModification mh);

//CellBuffer
private:
	SplitVector<char> substance;
	SplitVector<char> style;

	LineVector lv;
};

/**
 * To optimise processing of document modifications by DocWatchers, a hint is passed indicating the
 * scope of the change.
 * If the DocWatcher is a document view then this can be used to optimise screen updating.
 */
class DocModification {
public:
  	int modificationType;
	int position;
 	int length;
 	int linesAdded;	/**< Negative if lines deleted. */
 	const char *text;	/**< Only valid for changes to text, not for changes to style. */
 	int line;
	int foldLevelNow;
	int foldLevelPrev;
	int annotationLinesAdded;
	int token;

	DocModification(int modificationType_, int position_=0, int length_=0,
		int linesAdded_=0, const char *text_=0, int line_=0) :
		modificationType(modificationType_),
		position(position_),
		length(length_),
		linesAdded(linesAdded_),
		text(text_),
		line(line_),
		foldLevelNow(0),
		foldLevelPrev(0),
		annotationLinesAdded(0),
		token(0) {}

	DocModification(int modificationType_, const Action &act, int linesAdded_=0) :
		modificationType(modificationType_),
		position(act.position),
		length(act.lenData),
		linesAdded(linesAdded_),
		text(act.data),
		line(0),
		foldLevelNow(0),
		foldLevelPrev(0),
		annotationLinesAdded(0),
		token(0) {}
};

/**
 * A class that wants to receive notifications from a Document must be derived from DocWatcher
 * and implement the notification methods. It can then be added to the watcher list with AddWatcher.
 */
class DocWatcher {
public:
	virtual ~DocWatcher() {}

	virtual void NotifyModifyAttempt(Document *doc, void *userData) = 0;
	virtual void NotifySavePoint(Document *doc, void *userData, bool atSavePoint) = 0;
	virtual void NotifyModified(Document *doc, DocModification mh, void *userData) = 0;
	virtual void NotifyDeleted(Document *doc, void *userData) = 0;
	virtual void NotifyStyleNeeded(Document *doc, void *userData, int endPos) = 0;
	virtual void NotifyLexerChanged(Document *doc, void *userData) = 0;
	virtual void NotifyErrorOccurred(Document *doc, void *userData, int status) = 0;
};

#ifdef SCI_NAMESPACE
}
#endif

#endif
