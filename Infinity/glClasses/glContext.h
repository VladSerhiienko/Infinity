enum
{
	USAGE_POSITION,
	USAGE_COLOR,
	USAGE_SECONDARYCOLOR,
	USAGE_NORMAL,
	USAGE_TEXCOORD0,
	USAGE_TEXCOORD1,
	USAGE_TEXCOORD2,
	USAGE_TEXCOORD3,
	USAGE_TEXCOORD4,
	USAGE_TEXCOORD5,
	USAGE_TEXCOORD6,
	USAGE_TEXCOORD7,
	USAGE_ATTRIB_BASE
};

#define USAGE_ATTRIB(attr_loc) (attr_loc+USAGE_ATTRIB_BASE)
#define BUFFER_OFFSET(i) ((char*)0 + (i))

struct VertexDeclaration
{
	int usage_, elCount_, elType_, offset_, stride_;
};

class Context
{
	private:
		int	indType_;
	public:
		void begin()
		{
			indType_=0;
			glPushAttrib(GL_ALL_ATTRIB_BITS);
			glPushClientAttrib(GL_CLIENT_ALL_ATTRIB_BITS);
		}
		void end()
		{
			glUseProgram(0);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			glPopClientAttrib();
			glPopAttrib();
		}
		void addAttribBuffer(AttribBuffer* buffer, GLuint numEntries=0, VertexDeclaration *decl=0);
		void addAttribBuffer(AttribBuffer& buffer, GLuint numEntries, VertexDeclaration *decl)
		{
			addAttribBuffer(&buffer, numEntries, decl);
		}
		void setIndexBuffer(IndexBuffer& buffer, GLenum type)
		{
			setIndexBuffer(&buffer, type);
		}
		void setIndexBuffer(IndexBuffer* buffer, GLenum type=0)
		{
			indType_ = type;
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer?buffer->mHandle:0);
		}
		void drawPrimitives(GLenum primType, GLuint indCount, const GLvoid* indices=0)//may be use default start primitive etc.
		{
			glDrawElements(primType, indCount, indType_, indices);
		}
		void callCommandList(CommandList* list)
		{
			if (list) glCallList(list->mHandle);
		}
		void callCommandList(CommandList& list)
		{
			glCallList(list.mHandle);
		}
		void setTexture(GLenum stage, Texture& texture)
		{
			setTexture(stage, &texture);
		}
		void setTexture(GLenum stage, Texture* texture)
		{
			glActiveTexture(stage);
			if( texture )
				glBindTexture(texture->target_, texture->mHandle);
			else
				glBindTexture(GL_TEXTURE_2D, 0);
		}
		void useProgram(Program* program)
		{
			if (program) glUseProgram(*program);
		}
		void useProgram(Program& program)
		{
			glUseProgram(program);
		}
		void setUniform1f(GLint location, GLfloat v0)
		{
			glUniform1f(location, v0);
		}
		void setUniform2f(GLint location, GLfloat v0, GLfloat v1)
		{
			glUniform2f(location, v0, v1);
		}
		void setUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2)
		{
			glUniform3f(location, v0, v1, v2);
		}
		void setUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
		{
			glUniform4f(location, v0, v1, v2, v3);
		}
		void setUniform1fv(GLint location, GLsizei count, const GLfloat* value)
		{
			glUniform1fv(location, count, value);
		}
		void setUniform2fv(GLint location, GLsizei count, const GLfloat* value)
		{
			glUniform2fv(location, count, value);
		}
		void setUniform3fv(GLint location, GLsizei count, const GLfloat* value)
		{
			glUniform3fv(location, count, value);
		}
		void setUniform4fv(GLint location, GLsizei count, const GLfloat* value)
		{
			glUniform4fv(location, count, value);
		}
		void setUniform1i(GLint location, GLint v0)
		{
			glUniform1i(location, v0);
		}
		void setUniform2i(GLint location, GLint v0, GLint v1)
		{
			glUniform2i(location, v0, v1);
		}
		void setUniform3i(GLint location, GLint v0, GLint v1, GLint v2)
		{
			glUniform3i(location, v0, v1, v2);
		}
		void setUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3)
		{
			glUniform4i(location, v0, v1, v2, v3);
		}
		void setUniform1iv(GLint location, GLsizei count, const GLint* value)
		{
			glUniform1iv(location, count, value);
		}
		void setUniform2iv(GLint location, GLsizei count, const GLint* value)
		{
			glUniform2iv(location, count, value);
		}
		void setUniform3iv(GLint location, GLsizei count, const GLint* value)
		{
			glUniform3iv(location, count, value);
		}
		void setUniform4iv(GLint location, GLsizei count, const GLint* value)
		{
			glUniform4iv(location, count, value);
		}
		void setUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
		{
			glUniformMatrix2fv(location, count, transpose, value);
		}
		void setUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
		{
			glUniformMatrix3fv(location, count, transpose, value);
		}
		void setUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
		{
			glUniformMatrix4fv(location, count, transpose, value);
		}
		//and so on...
};