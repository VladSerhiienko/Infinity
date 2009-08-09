//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 - 2006 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2006-04-20
// Updated : 2006-12-03
// Licence : This source is under GNU LGPL licence
// File    : _swizzle.h
//////////////////////////////////////////////////////////////////////////////////

#ifndef __swizzle_h__
#define __swizzle_h__

namespace glm
{

}

#if defined(GLM_SWIZZLE) && (GLM_SWIZZLE & GLM_SWIZZLE_XYZW)

// 2 components common swizzle operators
#define xx _xx()
#define yx _yx()
#define zx _zx()
#define wx _wx()
#define xy _xy()
#define yy _yy()
#define zy _zy()
#define wy _wy()
#define xz _xz()
#define yz _yz()
#define zz _zz()
#define wz _wz()
#define xw _xw()
#define yw _yw()
#define zw _zw()
#define ww _ww()

// 3 components common swizzle operators
#define xxx _xxx()
#define yxx _yxx()
#define zxx _zxx()
#define wxx _wxx()
#define xyx _xyx()
#define yyx _yyx()
#define zyx _zyx()
#define wyx _wyx()
#define xzx _xzx()
#define yzx _yzx()
#define zzx _zzx()
#define wzx _wzx()
#define xwx _xwx()
#define ywx _ywx()
#define zwx _zwx()
#define wwx _wwx()
#define xxy _xxy()
#define yxy _yxy()
#define zxy _zxy()
#define wxy _wxy()
#define xyy _xyy()
#define yyy _yyy()
#define zyy _zyy()
#define wyy _wyy()
#define xzy _xzy()
#define yzy _yzy()
#define zzy _zzy()
#define wzy _wzy()
#define xwy _xwy()
#define ywy _ywy()
#define zwy _zwy()
#define wwy _wwy()
#define xxz _xxz()
#define yxz _yxz()
#define zxz _zxz()
#define wxz _wxz()
#define xyz _xyz()
#define yyz _yyz()
#define zyz _zyz()
#define wyz _wyz()
#define xzz _xzz()
#define yzz _yzz()
#define zzz _zzz()
#define wzz _wzz()
#define xwz _xwz()
#define ywz _ywz()
#define zwz _zwz()
#define wwz _wwz()
#define xxw _xxw()
#define yxw _yxw()
#define zxw _zxw()
#define wxw _wxw()
#define xyw _xyw()
#define yyw _yyw()
#define zyw _zyw()
#define wyw _wyw()
#define xzw _xzw()
#define yzw _yzw()
#define zzw _zzw()
#define wzw _wzw()
#define xww _xww()
#define yww _yww()
#define zww _zww()
#define www _www()

// 4 components common swizzle operators
#define xxxx _xxxx()
#define yxxx _yxxx()
#define zxxx _zxxx()
#define wxxx _wxxx()
#define xyxx _xyxx()
#define yyxx _yyxx()
#define zyxx _zyxx()
#define wyxx _wyxx()
#define xzxx _xzxx()
#define yzxx _yzxx()
#define zzxx _zzxx()
#define wzxx _wzxx()
#define xwxx _xwxx()
#define ywxx _ywxx()
#define zwxx _zwxx()
#define wwxx _wwxx()
#define xxyx _xxyx()
#define yxyx _yxyx()
#define zxyx _zxyx()
#define wxyx _wxyx()
#define xyyx _xyyx()
#define yyyx _yyyx()
#define zyyx _zyyx()
#define wyyx _wyyx()
#define xzyx _xzyx()
#define yzyx _yzyx()
#define zzyx _zzyx()
#define wzyx _wzyx()
#define xwyx _xwyx()
#define ywyx _ywyx()
#define zwyx _zwyx()
#define wwyx _wwyx()
#define xxzx _xxzx()
#define yxzx _yxzx()
#define zxzx _zxzx()
#define wxzx _wxzx()
#define xyzx _xyzx()
#define yyzx _yyzx()
#define zyzx _zyzx()
#define wyzx _wyzx()
#define xzzx _xzzx()
#define yzzx _yzzx()
#define zzzx _zzzx()
#define wzzx _wzzx()
#define xwzx _xwzx()
#define ywzx _ywzx()
#define zwzx _zwzx()
#define wwzx _wwzx()
#define xxwx _xxwx()
#define yxwx _yxwx()
#define zxwx _zxwx()
#define wxwx _wxwx()
#define xywx _xywx()
#define yywx _yywx()
#define zywx _zywx()
#define wywx _wywx()
#define xzwx _xzwx()
#define yzwx _yzwx()
#define zzwx _zzwx()
#define wzwx _wzwx()
#define xwwx _xwwx()
#define ywwx _ywwx()
#define zwwx _zwwx()
#define wwwx _wwwx()
#define xxxy _xxxy()
#define yxxy _yxxy()
#define zxxy _zxxy()
#define wxxy _wxxy()
#define xyxy _xyxy()
#define yyxy _yyxy()
#define zyxy _zyxy()
#define wyxy _wyxy()
#define xzxy _xzxy()
#define yzxy _yzxy()
#define zzxy _zzxy()
#define wzxy _wzxy()
#define xwxy _xwxy()
#define ywxy _ywxy()
#define zwxy _zwxy()
#define wwxy _wwxy()
#define xxyy _xxyy()
#define yxyy _yxyy()
#define zxyy _zxyy()
#define wxyy _wxyy()
#define xyyy _xyyy()
#define yyyy _yyyy()
#define zyyy _zyyy()
#define wyyy _wyyy()
#define xzyy _xzyy()
#define yzyy _yzyy()
#define zzyy _zzyy()
#define wzyy _wzyy()
#define xwyy _xwyy()
#define ywyy _ywyy()
#define zwyy _zwyy()
#define wwyy _wwyy()
#define xxzy _xxzy()
#define yxzy _yxzy()
#define zxzy _zxzy()
#define wxzy _wxzy()
#define xyzy _xyzy()
#define yyzy _yyzy()
#define zyzy _zyzy()
#define wyzy _wyzy()
#define xzzy _xzzy()
#define yzzy _yzzy()
#define zzzy _zzzy()
#define wzzy _wzzy()
#define xwzy _xwzy()
#define ywzy _ywzy()
#define zwzy _zwzy()
#define wwzy _wwzy()
#define xxwy _xxwy()
#define yxwy _yxwy()
#define zxwy _zxwy()
#define wxwy _wxwy()
#define xywy _xywy()
#define yywy _yywy()
#define zywy _zywy()
#define wywy _wywy()
#define xzwy _xzwy()
#define yzwy _yzwy()
#define zzwy _zzwy()
#define wzwy _wzwy()
#define xwwy _xwwy()
#define ywwy _ywwy()
#define zwwy _zwwy()
#define wwwy _wwwy()
#define xxxz _xxxz()
#define yxxz _yxxz()
#define zxxz _zxxz()
#define wxxz _wxxz()
#define xyxz _xyxz()
#define yyxz _yyxz()
#define zyxz _zyxz()
#define wyxz _wyxz()
#define xzxz _xzxz()
#define yzxz _yzxz()
#define zzxz _zzxz()
#define wzxz _wzxz()
#define xwxz _xwxz()
#define ywxz _ywxz()
#define zwxz _zwxz()
#define wwxz _wwxz()
#define xxyz _xxyz()
#define yxyz _yxyz()
#define zxyz _zxyz()
#define wxyz _wxyz()
#define xyyz _xyyz()
#define yyyz _yyyz()
#define zyyz _zyyz()
#define wyyz _wyyz()
#define xzyz _xzyz()
#define yzyz _yzyz()
#define zzyz _zzyz()
#define wzyz _wzyz()
#define xwyz _xwyz()
#define ywyz _ywyz()
#define zwyz _zwyz()
#define wwyz _wwyz()
#define xxzz _xxzz()
#define yxzz _yxzz()
#define zxzz _zxzz()
#define wxzz _wxzz()
#define xyzz _xyzz()
#define yyzz _yyzz()
#define zyzz _zyzz()
#define wyzz _wyzz()
#define xzzz _xzzz()
#define yzzz _yzzz()
#define zzzz _zzzz()
#define wzzz _wzzz()
#define xwzz _xwzz()
#define ywzz _ywzz()
#define zwzz _zwzz()
#define wwzz _wwzz()
#define xxwz _xxwz()
#define yxwz _yxwz()
#define zxwz _zxwz()
#define wxwz _wxwz()
#define xywz _xywz()
#define yywz _yywz()
#define zywz _zywz()
#define wywz _wywz()
#define xzwz _xzwz()
#define yzwz _yzwz()
#define zzwz _zzwz()
#define wzwz _wzwz()
#define xwwz _xwwz()
#define ywwz _ywwz()
#define zwwz _zwwz()
#define wwwz _wwwz()
#define xxxw _xxxw()
#define yxxw _yxxw()
#define zxxw _zxxw()
#define wxxw _wxxw()
#define xyxw _xyxw()
#define yyxw _yyxw()
#define zyxw _zyxw()
#define wyxw _wyxw()
#define xzxw _xzxw()
#define yzxw _yzxw()
#define zzxw _zzxw()
#define wzxw _wzxw()
#define xwxw _xwxw()
#define ywxw _ywxw()
#define zwxw _zwxw()
#define wwxw _wwxw()
#define xxyw _xxyw()
#define yxyw _yxyw()
#define zxyw _zxyw()
#define wxyw _wxyw()
#define xyyw _xyyw()
#define yyyw _yyyw()
#define zyyw _zyyw()
#define wyyw _wyyw()
#define xzyw _xzyw()
#define yzyw _yzyw()
#define zzyw _zzyw()
#define wzyw _wzyw()
#define xwyw _xwyw()
#define ywyw _ywyw()
#define zwyw _zwyw()
#define wwyw _wwyw()
#define xxzw _xxzw()
#define yxzw _yxzw()
#define zxzw _zxzw()
#define wxzw _wxzw()
#define xyzw _xyzw()
#define yyzw _yyzw()
#define zyzw _zyzw()
#define wyzw _wyzw()
#define xzzw _xzzw()
#define yzzw _yzzw()
#define zzzw _zzzw()
#define wzzw _wzzw()
#define xwzw _xwzw()
#define ywzw _ywzw()
#define zwzw _zwzw()
#define wwzw _wwzw()
#define xxww _xxww()
#define yxww _yxww()
#define zxww _zxww()
#define wxww _wxww()
#define xyww _xyww()
#define yyww _yyww()
#define zyww _zyww()
#define wyww _wyww()
#define xzww _xzww()
#define yzww _yzww()
#define zzww _zzww()
#define wzww _wzww()
#define xwww _xwww()
#define ywww _ywww()
#define zwww _zwww()
#define wwww _wwww()

#endif//defined(GLM_SWIZZLE) && (GLM_SWIZZLE & GLM_SWIZZLE_XYZW)

#if defined(GLM_SWIZZLE) && (GLM_SWIZZLE & GLM_SWIZZLE_RGBA)

// 2 components color swizzle operators
#define rr _xx()
#define gr _yx()
#define br _zx()
#define ar _wx()
#define rg _xy()
#define gg _yy()
#define bg _zy()
#define ag _wy()
#define rb _xz()
#define gb _yz()
#define bb _zz()
#define ab _wz()
#define ra _xw()
#define ga _yw()
#define ba _zw()
#define aa _ww()

// 3 components color swizzle operators
#define rrr _xxx()
#define grr _yxx()
#define brr _zxx()
#define arr _wxx()
#define rgr _xyx()
#define ggr _yyx()
#define bgr _zyx()
#define agr _wyx()
#define rbr _xzx()
#define gbr _yzx()
#define bbr _zzx()
#define abr _wzx()
#define rar _xwx()
#define gar _ywx()
#define bar _zwx()
#define aar _wwx()
#define rrg _xxy()
#define grg _yxy()
#define brg _zxy()
#define arg _wxy()
#define rgg _xyy()
#define ggg _yyy()
#define bgg _zyy()
#define agg _wyy()
#define rbg _xzy()
#define gbg _yzy()
#define bbg _zzy()
#define abg _wzy()
#define rag _xwy()
#define gag _ywy()
#define bag _zwy()
#define aag _wwy()
#define rrb _xxz()
#define grb _yxz()
#define brb _zxz()
#define arb _wxz()
#define rgb _xyz()
#define ggb _yyz()
#define bgb _zyz()
#define agb _wyz()
#define rbb _xzz()
#define gbb _yzz()
#define bbb _zzz()
#define abb _wzz()
#define rab _xwz()
#define gab _ywz()
#define bab _zwz()
#define aab _wwz()
#define rra _xxw()
#define gra _yxw()
#define bra _zxw()
#define ara _wxw()
#define rga _xyw()
#define gga _yyw()
#define bga _zyw()
#define aga _wyw()
#define rba _xzw()
#define gba _yzw()
#define bba _zzw()
#define aba _wzw()
#define raa _xww()
#define gaa _yww()
#define baa _zww()
#define aaa _www()

// 4 components color swizzle operators
#define rrrr _xxxx()
#define grrr _yxxx()
#define brrr _zxxx()
#define arrr _wxxx()
#define rgrr _xyxx()
#define ggrr _yyxx()
#define bgrr _zyxx()
#define agrr _wyxx()
#define rbrr _xzxx()
#define gbrr _yzxx()
#define bbrr _zzxx()
#define abrr _wzxx()
#define rarr _xwxx()
#define garr _ywxx()
#define barr _zwxx()
#define aarr _wwxx()
#define rrgr _xxyx()
#define grgr _yxyx()
#define brgr _zxyx()
#define argr _wxyx()
#define rggr _xyyx()
#define gggr _yyyx()
#define bggr _zyyx()
#define aggr _wyyx()
#define rbgr _xzyx()
#define gbgr _yzyx()
#define bbgr _zzyx()
#define abgr _wzyx()
#define ragr _xwyx()
#define gagr _ywyx()
#define bagr _zwyx()
#define aagr _wwyx()
#define rrbr _xxzx()
#define grbr _yxzx()
#define brbr _zxzx()
#define arbr _wxzx()
#define rgbr _xyzx()
#define ggbr _yyzx()
#define bgbr _zyzx()
#define agbr _wyzx()
#define rbbr _xzzx()
#define gbbr _yzzx()
#define bbbr _zzzx()
#define abbr _wzzx()
#define rabr _xwzx()
#define gabr _ywzx()
#define babr _zwzx()
#define aabr _wwzx()
#define rrar _xxwx()
#define grar _yxwx()
#define brar _zxwx()
#define arar _wxwx()
#define rgar _xywx()
#define ggar _yywx()
#define bgar _zywx()
#define agar _wywx()
#define rbar _xzwx()
#define gbar _yzwx()
#define bbar _zzwx()
#define abar _wzwx()
#define raar _xwwx()
#define gaar _ywwx()
#define baar _zwwx()
#define aaar _wwwx()
#define rrrg _xxxy()
#define grrg _yxxy()
#define brrg _zxxy()
#define arrg _wxxy()
#define rgrg _xyxy()
#define ggrg _yyxy()
#define bgrg _zyxy()
#define agrg _wyxy()
#define rbrg _xzxy()
#define gbrg _yzxy()
#define bbrg _zzxy()
#define abrg _wzxy()
#define rarg _xwxy()
#define garg _ywxy()
#define barg _zwxy()
#define aarg _wwxy()
#define rrgg _xxyy()
#define grgg _yxyy()
#define brgg _zxyy()
#define argg _wxyy()
#define rggg _xyyy()
#define gggg _yyyy()
#define bggg _zyyy()
#define aggg _wyyy()
#define rbgg _xzyy()
#define gbgg _yzyy()
#define bbgg _zzyy()
#define abgg _wzyy()
#define ragg _xwyy()
#define gagg _ywyy()
#define bagg _zwyy()
#define aagg _wwyy()
#define rrbg _xxzy()
#define grbg _yxzy()
#define brbg _zxzy()
#define arbg _wxzy()
#define rgbg _xyzy()
#define ggbg _yyzy()
#define bgbg _zyzy()
#define agbg _wyzy()
#define rbbg _xzzy()
#define gbbg _yzzy()
#define bbbg _zzzy()
#define abbg _wzzy()
#define rabg _xwzy()
#define gabg _ywzy()
#define babg _zwzy()
#define aabg _wwzy()
#define rrag _xxwy()
#define grag _yxwy()
#define brag _zxwy()
#define arag _wxwy()
#define rgag _xywy()
#define ggag _yywy()
#define bgag _zywy()
#define agag _wywy()
#define rbag _xzwy()
#define gbag _yzwy()
#define bbag _zzwy()
#define abag _wzwy()
#define raag _xwwy()
#define gaag _ywwy()
#define baag _zwwy()
#define aaag _wwwy()
#define rrrb _xxxz()
#define grrb _yxxz()
#define brrb _zxxz()
#define arrb _wxxz()
#define rgrb _xyxz()
#define ggrb _yyxz()
#define bgrb _zyxz()
#define agrb _wyxz()
#define rbrb _xzxz()
#define gbrb _yzxz()
#define bbrb _zzxz()
#define abrb _wzxz()
#define rarb _xwxz()
#define garb _ywxz()
#define barb _zwxz()
#define aarb _wwxz()
#define rrgb _xxyz()
#define grgb _yxyz()
#define brgb _zxyz()
#define argb _wxyz()
#define rggb _xyyz()
#define gggb _yyyz()
#define bggb _zyyz()
#define aggb _wyyz()
#define rbgb _xzyz()
#define gbgb _yzyz()
#define bbgb _zzyz()
#define abgb _wzyz()
#define ragb _xwyz()
#define gagb _ywyz()
#define bagb _zwyz()
#define aagb _wwyz()
#define rrbb _xxzz()
#define grbb _yxzz()
#define brbb _zxzz()
#define arbb _wxzz()
#define rgbb _xyzz()
#define ggbb _yyzz()
#define bgbb _zyzz()
#define agbb _wyzz()
#define rbbb _xzzz()
#define gbbb _yzzz()
#define bbbb _zzzz()
#define abbb _wzzz()
#define rabb _xwzz()
#define gabb _ywzz()
#define babb _zwzz()
#define aabb _wwzz()
#define rrab _xxwz()
#define grab _yxwz()
#define brab _zxwz()
#define arab _wxwz()
#define rgab _xywz()
#define ggab _yywz()
#define bgab _zywz()
#define agab _wywz()
#define rbab _xzwz()
#define gbab _yzwz()
#define bbab _zzwz()
#define abab _wzwz()
#define raab _xwwz()
#define gaab _ywwz()
#define baab _zwwz()
#define aaab _wwwz()
#define rrra _xxxw()
#define grra _yxxw()
#define brra _zxxw()
#define arra _wxxw()
#define rgra _xyxw()
#define ggra _yyxw()
#define bgra _zyxw()
#define agra _wyxw()
#define rbra _xzxw()
#define gbra _yzxw()
#define bbra _zzxw()
#define abra _wzxw()
#define rara _xwxw()
#define gara _ywxw()
#define bara _zwxw()
#define aara _wwxw()
#define rrga _xxyw()
#define grga _yxyw()
#define brga _zxyw()
#define arga _wxyw()
#define rgga _xyyw()
#define ggga _yyyw()
#define bgga _zyyw()
#define agga _wyyw()
#define rbga _xzyw()
#define gbga _yzyw()
#define bbga _zzyw()
#define abga _wzyw()
#define raga _xwyw()
#define gaga _ywyw()
#define baga _zwyw()
#define aaga _wwyw()
#define rrba _xxzw()
#define grba _yxzw()
#define brba _zxzw()
#define arba _wxzw()
#define rgba _xyzw()
#define ggba _yyzw()
#define bgba _zyzw()
#define agba _wyzw()
#define rbba _xzzw()
#define gbba _yzzw()
#define bbba _zzzw()
#define abba _wzzw()
#define raba _xwzw()
#define gaba _ywzw()
#define baba _zwzw()
#define aaba _wwzw()
#define rraa _xxww()
#define graa _yxww()
#define braa _zxww()
#define araa _wxww()
#define rgaa _xyww()
#define ggaa _yyww()
#define bgaa _zyww()
#define agaa _wyww()
#define rbaa _xzww()
#define gbaa _yzww()
#define bbaa _zzww()
#define abaa _wzww()
#define raaa _xwww()
#define gaaa _ywww()
#define baaa _zwww()
#define aaaa _wwww()

#endif//defined(GLM_SWIZZLE) && defined(GLM_SWIZZLE_RGBA)

#if defined(GLM_SWIZZLE) && (GLM_SWIZZLE & GLM_SWIZZLE_STQP)

// 2 components texcoord swizzle operators
#define ss _xx()
#define ts _yx()
#define ps _zx()
#define qs _wx()
#define st _xy()
#define tt _yy()
#define pt _zy()
#define qt _qy()
#define sp _xz()
#define tp _yz()
#define pp _zz()
#define qp _qz()
#define sq _xq()
#define tq _yq()
#define pq _zq()
#define qq _qq()

// 3 components tescoord swizzle operators
#define sss _xxx()
#define tss _yxx()
#define pss _zxx()
#define qss _qxx()
#define sts _xyx()
#define tts _yyx()
#define pts _zyx()
#define qts _qyx()
#define sps _xzx()
#define tps _yzx()
#define pps _zzx()
#define qps _qzx()
#define sqs _xqx()
#define tqs _yqx()
#define pqs _zqx()
#define qqs _qqx()
#define sst _xxy()
#define tst _yxy()
#define pst _zxy()
#define qst _qxy()
#define stt _xyy()
#define ttt _yyy()
#define ptt _zyy()
#define qtt _qyy()
#define spt _xzy()
#define tpt _yzy()
#define ppt _zzy()
#define qpt _qzy()
#define sqt _xqy()
#define tqt _yqy()
#define pqt _zqy()
#define qqt _qqy()
#define ssp _xxz()
#define tsp _yxz()
#define psp _zxz()
#define qsp _qxz()
#define stp _xyz()
#define ttp _yyz()
#define ptp _zyz()
#define qtp _qyz()
#define spp _xzz()
#define tpp _yzz()
#define ppp _zzz()
#define qpp _qzz()
#define sqp _xqz()
#define tqp _yqz()
#define pqp _zqz()
#define qqp _qqz()
#define ssq _xxq()
#define tsq _yxq()
#define psq _zxq()
#define qsq _qxq()
#define stq _xyq()
#define ttq _yyq()
#define ptq _zyq()
#define qtq _qyq()
#define spq _xzq()
#define tpq _yzq()
#define ppq _zzq()
#define qpq _qzq()
#define sqq _xqq()
#define tqq _yqq()
#define pqq _zqq()
#define qqq _qqq()

// 4 components tescoord swizzle operators
#define ssss _xxxx()
#define tsss _yxxx()
#define psss _zxxx()
#define qsss _qxxx()
#define stss _xyxx()
#define ttss _yyxx()
#define ptss _zyxx()
#define qtss _qyxx()
#define spss _xzxx()
#define tpss _yzxx()
#define ppss _zzxx()
#define qpss _qzxx()
#define sqss _xqxx()
#define tqss _yqxx()
#define pqss _zqxx()
#define qqss _qqxx()
#define ssts _xxyx()
#define tsts _yxyx()
#define psts _zxyx()
#define qsts _qxyx()
#define stts _xyyx()
#define ttts _yyyx()
#define ptts _zyyx()
#define qtts _qyyx()
#define spts _xzyx()
#define tpts _yzyx()
#define ppts _zzyx()
#define qpts _qzyx()
#define sqts _xqyx()
#define tqts _yqyx()
#define pqts _zqyx()
#define qqts _qqyx()
#define ssps _xxzx()
#define tsps _yxzx()
#define psps _zxzx()
#define qsps _qxzx()
#define stps _xyzx()
#define ttps _yyzx()
#define ptps _zyzx()
#define qtps _qyzx()
#define spps _xzzx()
#define tpps _yzzx()
#define ppps _zzzx()
#define qpps _qzzx()
#define sqps _xqzx()
#define tqps _yqzx()
#define pqps _zqzx()
#define qqps _qqzx()
#define ssqs _xxqx()
#define tsqs _yxqx()
#define psqs _zxqx()
#define qsqs _qxqx()
#define stqs _xyqx()
#define ttqs _yyqx()
#define ptqs _zyqx()
#define qtqs _qyqx()
#define spqs _xzqx()
#define tpqs _yzqx()
#define ppqs _zzqx()
#define qpqs _qzqx()
#define sqqs _xqqx()
#define tqqs _yqqx()
#define pqqs _zqqx()
#define qqqs _qqqx()
#define ssst _xxxy()
#define tsst _yxxy()
#define psst _zxxy()
#define qsst _qxxy()
#define stst _xyxy()
#define ttst _yyxy()
#define ptst _zyxy()
#define qtst _qyxy()
#define spst _xzxy()
#define tpst _yzxy()
#define ppst _zzxy()
#define qpst _qzxy()
#define sqst _xqxy()
#define tqst _yqxy()
#define pqst _zqxy()
#define qqst _qqxy()
#define sstt _xxyy()
#define tstt _yxyy()
#define pstt _zxyy()
#define qstt _qxyy()
#define sttt _xyyy()
#define tttt _yyyy()
#define pttt _zyyy()
#define qttt _qyyy()
#define sptt _xzyy()
#define tptt _yzyy()
#define pptt _zzyy()
#define qptt _qzyy()
#define sqtt _xqyy()
#define tqtt _yqyy()
#define pqtt _zqyy()
#define qqtt _qqyy()
#define sspt _xxzy()
#define tspt _yxzy()
#define pspt _zxzy()
#define qspt _qxzy()
#define stpt _xyzy()
#define ttpt _yyzy()
#define ptpt _zyzy()
#define qtpt _qyzy()
#define sppt _xzzy()
#define tppt _yzzy()
#define pppt _zzzy()
#define qppt _qzzy()
#define sqpt _xqzy()
#define tqpt _yqzy()
#define pqpt _zqzy()
#define qqpt _qqzy()
#define ssqt _xxqy()
#define tsqt _yxqy()
#define psqt _zxqy()
#define qsqt _qxqy()
#define stqt _xyqy()
#define ttqt _yyqy()
#define ptqt _zyqy()
#define qtqt _qyqy()
#define spqt _xzqy()
#define tpqt _yzqy()
#define ppqt _zzqy()
#define qpqt _qzqy()
#define sqqt _xqqy()
#define tqqt _yqqy()
#define pqqt _zqqy()
#define qqqt _qqqy()
#define sssp _xxxz()
#define tssp _yxxz()
#define pssp _zxxz()
#define qssp _qxxz()
#define stsp _xyxz()
#define ttsp _yyxz()
#define ptsp _zyxz()
#define qtsp _qyxz()
#define spsp _xzxz()
#define tpsp _yzxz()
#define ppsp _zzxz()
#define qpsp _qzxz()
#define sqsp _xqxz()
#define tqsp _yqxz()
#define pqsp _zqxz()
#define qqsp _qqxz()
#define sstp _xxyz()
#define tstp _yxyz()
#define pstp _zxyz()
#define qstp _qxyz()
#define sttp _xyyz()
#define tttp _yyyz()
#define pttp _zyyz()
#define qttp _qyyz()
#define sptp _xzyz()
#define tptp _yzyz()
#define pptp _zzyz()
#define qptp _qzyz()
#define sqtp _xqyz()
#define tqtp _yqyz()
#define pqtp _zqyz()
#define qqtp _qqyz()
#define sspp _xxzz()
#define tspp _yxzz()
#define pspp _zxzz()
#define qspp _qxzz()
#define stpp _xyzz()
#define ttpp _yyzz()
#define ptpp _zyzz()
#define qtpp _qyzz()
#define sppp _xzzz()
#define tppp _yzzz()
#define pppp _zzzz()
#define qppp _qzzz()
#define sqpp _xqzz()
#define tqpp _yqzz()
#define pqpp _zqzz()
#define qqpp _qqzz()
#define ssqp _xxqz()
#define tsqp _yxqz()
#define psqp _zxqz()
#define qsqp _qxqz()
#define stqp _xyqz()
#define ttqp _yyqz()
#define ptqp _zyqz()
#define qtqp _qyqz()
#define spqp _xzqz()
#define tpqp _yzqz()
#define ppqp _zzqz()
#define qpqp _qzqz()
#define sqqp _xqqz()
#define tqqp _yqqz()
#define pqqp _zqqz()
#define qqqp _qqqz()
#define sssq _xxxq()
#define tssq _yxxq()
#define pssq _zxxq()
#define qssq _qxxq()
#define stsq _xyxq()
#define ttsq _yyxq()
#define ptsq _zyxq()
#define qtsq _qyxq()
#define spsq _xzxq()
#define tpsq _yzxq()
#define ppsq _zzxq()
#define qpsq _qzxq()
#define sqsq _xqxq()
#define tqsq _yqxq()
#define pqsq _zqxq()
#define qqsq _qqxq()
#define sstq _xxyq()
#define tstq _yxyq()
#define pstq _zxyq()
#define qstq _qxyq()
#define sttq _xyyq()
#define tttq _yyyq()
#define pttq _zyyq()
#define qttq _qyyq()
#define sptq _xzyq()
#define tptq _yzyq()
#define pptq _zzyq()
#define qptq _qzyq()
#define sqtq _xqyq()
#define tqtq _yqyq()
#define pqtq _zqyq()
#define qqtq _qqyq()
#define sspq _xxzq()
#define tspq _yxzq()
#define pspq _zxzq()
#define qspq _qxzq()
#define stpq _xyzq()
#define ttpq _yyzq()
#define ptpq _zyzq()
#define qtpq _qyzq()
#define sppq _xzzq()
#define tppq _yzzq()
#define pppq _zzzq()
#define qppq _qzzq()
#define sqpq _xqzq()
#define tqpq _yqzq()
#define pqpq _zqzq()
#define qqpq _qqzq()
#define ssqq _xxqq()
#define tsqq _yxqq()
#define psqq _zxqq()
#define qsqq _qxqq()
#define stqq _xyqq()
#define ttqq _yyqq()
#define ptqq _zyqq()
#define qtqq _qyqq()
#define spqq _xzqq()
#define tpqq _yzqq()
#define ppqq _zzqq()
#define qpqq _qzqq()
#define sqqq _xqqq()
#define tqqq _yqqq()
#define pqqq _zqqq()
#define qqqq _qqqq()

#endif//defined(GLM_SWIZZLE) && (GLM_SWIZZLE & GLM_SWIZZLE_STQP)

/*
// 2 components color swizzle operators
#define rr _rr()
#define gr _gr()
#define br _br()
#define ar _ar()
#define rg _rg()
#define gg _gg()
#define bg _bg()
#define ag _ag()
#define rb _rb()
#define gb _gb()
#define bb _bb()
#define ab _ab()
#define ra _ra()
#define ga _ga()
#define ba _ba()
#define aa _aa()

// 3 components color swizzle operators
#define rrr _rrr()
#define grr _grr()
#define brr _brr()
#define arr _arr()
#define rgr _rgr()
#define ggr _ggr()
#define bgr _bgr()
#define agr _agr()
#define rbr _rbr()
#define gbr _gbr()
#define bbr _bbr()
#define abr _abr()
#define rar _rar()
#define gar _gar()
#define bar _bar()
#define aar _aar()
#define rrg _rrg()
#define grg _grg()
#define brg _brg()
#define arg _arg()
#define rgg _rgg()
#define ggg _ggg()
#define bgg _bgg()
#define agg _agg()
#define rbg _rbg()
#define gbg _gbg()
#define bbg _bbg()
#define abg _abg()
#define rag _rag()
#define gag _gag()
#define bag _bag()
#define aag _aag()
#define rrb _rrb()
#define grb _grb()
#define brb _brb()
#define arb _arb()
#define rgb _rgb()
#define ggb _ggb()
#define bgb _bgb()
#define agb _agb()
#define rbb _rbb()
#define gbb _gbb()
#define bbb _bbb()
#define abb _abb()
#define rab _rab()
#define gab _gab()
#define bab _bab()
#define aab _aab()
#define rra _rra()
#define gra _gra()
#define bra _bra()
#define ara _ara()
#define rga _rga()
#define gga _gga()
#define bga _bga()
#define aga _aga()
#define rba _rba()
#define gba _gba()
#define bba _bba()
#define aba _aba()
#define raa _raa()
#define gaa _gaa()
#define baa _baa()
#define aaa _aaa()

// 4 components color swizzle operators
#define rrrr _rrrr()
#define grrr _grrr()
#define brrr _brrr()
#define arrr _arrr()
#define rgrr _rgrr()
#define ggrr _ggrr()
#define bgrr _bgrr()
#define agrr _agrr()
#define rbrr _rbrr()
#define gbrr _gbrr()
#define bbrr _bbrr()
#define abrr _abrr()
#define rarr _rarr()
#define garr _garr()
#define barr _barr()
#define aarr _aarr()
#define rrgr _rrgr()
#define grgr _grgr()
#define brgr _brgr()
#define argr _argr()
#define rggr _rggr()
#define gggr _gggr()
#define bggr _bggr()
#define aggr _aggr()
#define rbgr _rbgr()
#define gbgr _gbgr()
#define bbgr _bbgr()
#define abgr _abgr()
#define ragr _ragr()
#define gagr _gagr()
#define bagr _bagr()
#define aagr _aagr()
#define rrbr _rrbr()
#define grbr _grbr()
#define brbr _brbr()
#define arbr _arbr()
#define rgbr _rgbr()
#define ggbr _ggbr()
#define bgbr _bgbr()
#define agbr _agbr()
#define rbbr _rbbr()
#define gbbr _gbbr()
#define bbbr _bbbr()
#define abbr _abbr()
#define rabr _rabr()
#define gabr _gabr()
#define babr _babr()
#define aabr _aabr()
#define rrar _rrar()
#define grar _grar()
#define brar _brar()
#define arar _arar()
#define rgar _rgar()
#define ggar _ggar()
#define bgar _bgar()
#define agar _agar()
#define rbar _rbar()
#define gbar _gbar()
#define bbar _bbar()
#define abar _abar()
#define raar _raar()
#define gaar _gaar()
#define baar _baar()
#define aaar _aaar()
#define rrrg _rrrg()
#define grrg _grrg()
#define brrg _brrg()
#define arrg _arrg()
#define rgrg _rgrg()
#define ggrg _ggrg()
#define bgrg _bgrg()
#define agrg _agrg()
#define rbrg _rbrg()
#define gbrg _gbrg()
#define bbrg _bbrg()
#define abrg _abrg()
#define rarg _rarg()
#define garg _garg()
#define barg _barg()
#define aarg _aarg()
#define rrgg _rrgg()
#define grgg _grgg()
#define brgg _brgg()
#define argg _argg()
#define rggg _rggg()
#define gggg _gggg()
#define bggg _bggg()
#define aggg _aggg()
#define rbgg _rbgg()
#define gbgg _gbgg()
#define bbgg _bbgg()
#define abgg _abgg()
#define ragg _ragg()
#define gagg _gagg()
#define bagg _bagg()
#define aagg _aagg()
#define rrbg _rrbg()
#define grbg _grbg()
#define brbg _brbg()
#define arbg _arbg()
#define rgbg _rgbg()
#define ggbg _ggbg()
#define bgbg _bgbg()
#define agbg _agbg()
#define rbbg _rbbg()
#define gbbg _gbbg()
#define bbbg _bbbg()
#define abbg _abbg()
#define rabg _rabg()
#define gabg _gabg()
#define babg _babg()
#define aabg _aabg()
#define rrag _rrag()
#define grag _grag()
#define brag _brag()
#define arag _arag()
#define rgag _rgag()
#define ggag _ggag()
#define bgag _bgag()
#define agag _agag()
#define rbag _rbag()
#define gbag _gbag()
#define bbag _bbag()
#define abag _abag()
#define raag _raag()
#define gaag _gaag()
#define baag _baag()
#define aaag _aaag()
#define rrrb _rrrb()
#define grrb _grrb()
#define brrb _brrb()
#define arrb _arrb()
#define rgrb _rgrb()
#define ggrb _ggrb()
#define bgrb _bgrb()
#define agrb _agrb()
#define rbrb _rbrb()
#define gbrb _gbrb()
#define bbrb _bbrb()
#define abrb _abrb()
#define rarb _rarb()
#define garb _garb()
#define barb _barb()
#define aarb _aarb()
#define rrgb _rrgb()
#define grgb _grgb()
#define brgb _brgb()
#define argb _argb()
#define rggb _rggb()
#define gggb _gggb()
#define bggb _bggb()
#define aggb _aggb()
#define rbgb _rbgb()
#define gbgb _gbgb()
#define bbgb _bbgb()
#define abgb _abgb()
#define ragb _ragb()
#define gagb _gagb()
#define bagb _bagb()
#define aagb _aagb()
#define rrbb _rrbb()
#define grbb _grbb()
#define brbb _brbb()
#define arbb _arbb()
#define rgbb _rgbb()
#define ggbb _ggbb()
#define bgbb _bgbb()
#define agbb _agbb()
#define rbbb _rbbb()
#define gbbb _gbbb()
#define bbbb _bbbb()
#define abbb _abbb()
#define rabb _rabb()
#define gabb _gabb()
#define babb _babb()
#define aabb _aabb()
#define rrab _rrab()
#define grab _grab()
#define brab _brab()
#define arab _arab()
#define rgab _rgab()
#define ggab _ggab()
#define bgab _bgab()
#define agab _agab()
#define rbab _rbab()
#define gbab _gbab()
#define bbab _bbab()
#define abab _abab()
#define raab _raab()
#define gaab _gaab()
#define baab _baab()
#define aaab _aaab()
#define rrra _rrra()
#define grra _grra()
#define brra _brra()
#define arra _arra()
#define rgra _rgra()
#define ggra _ggra()
#define bgra _bgra()
#define agra _agra()
#define rbra _rbra()
#define gbra _gbra()
#define bbra _bbra()
#define abra _abra()
#define rara _rara()
#define gara _gara()
#define bara _bara()
#define aara _aara()
#define rrga _rrga()
#define grga _grga()
#define brga _brga()
#define arga _arga()
#define rgga _rgga()
#define ggga _ggga()
#define bgga _bgga()
#define agga _agga()
#define rbga _rbga()
#define gbga _gbga()
#define bbga _bbga()
#define abga _abga()
#define raga _raga()
#define gaga _gaga()
#define baga _baga()
#define aaga _aaga()
#define rrba _rrba()
#define grba _grba()
#define brba _brba()
#define arba _arba()
#define rgba _rgba()
#define ggba _ggba()
#define bgba _bgba()
#define agba _agba()
#define rbba _rbba()
#define gbba _gbba()
#define bbba _bbba()
#define abba _abba()
#define raba _raba()
#define gaba _gaba()
#define baba _baba()
#define aaba _aaba()
#define rraa _rraa()
#define graa _graa()
#define braa _braa()
#define araa _araa()
#define rgaa _rgaa()
#define ggaa _ggaa()
#define bgaa _bgaa()
#define agaa _agaa()
#define rbaa _rbaa()
#define gbaa _gbaa()
#define bbaa _bbaa()
#define abaa _abaa()
#define raaa _raaa()
#define gaaa _gaaa()
#define baaa _baaa()
#define aaaa _aaaa()

// 2 components texcoord swizzle operators
#define ss _ss()
#define ts _ts()
#define ps _ps()
#define qs _qs()
#define st _st()
#define tt _tt()
#define pt _pt()
#define qt _qt()
#define sp _sp()
#define tp _tp()
#define pp _pp()
#define qp _qp()
#define sq _sq()
#define tq _tq()
#define pq _pq()
#define qq _qq()

// 3 components tescoord swizzle operators
#define sss _sss()
#define tss _tss()
#define pss _pss()
#define qss _qss()
#define sts _sts()
#define tts _tts()
#define pts _pts()
#define qts _qts()
#define sps _sps()
#define tps _tps()
#define pps _pps()
#define qps _qps()
#define sqs _sqs()
#define tqs _tqs()
#define pqs _pqs()
#define qqs _qqs()
#define sst _sst()
#define tst _tst()
#define pst _pst()
#define qst _qst()
#define stt _stt()
#define ttt _ttt()
#define ptt _ptt()
#define qtt _qtt()
#define spt _spt()
#define tpt _tpt()
#define ppt _ppt()
#define qpt _qpt()
#define sqt _sqt()
#define tqt _tqt()
#define pqt _pqt()
#define qqt _qqt()
#define ssp _ssp()
#define tsp _tsp()
#define psp _psp()
#define qsp _qsp()
#define stp _stp()
#define ttp _ttp()
#define ptp _ptp()
#define qtp _qtp()
#define spp _spp()
#define tpp _tpp()
#define ppp _ppp()
#define qpp _qpp()
#define sqp _sqp()
#define tqp _tqp()
#define pqp _pqp()
#define qqp _qqp()
#define ssq _ssq()
#define tsq _tsq()
#define psq _psq()
#define qsq _qsq()
#define stq _stq()
#define ttq _ttq()
#define ptq _ptq()
#define qtq _qtq()
#define spq _spq()
#define tpq _tpq()
#define ppq _ppq()
#define qpq _qpq()
#define sqq _sqq()
#define tqq _tqq()
#define pqq _pqq()
#define qqq _qqq()

// 4 components tescoord swizzle operators
#define ssss _ssss()
#define tsss _tsss()
#define psss _psss()
#define qsss _qsss()
#define stss _stss()
#define ttss _ttss()
#define ptss _ptss()
#define qtss _qtss()
#define spss _spss()
#define tpss _tpss()
#define ppss _ppss()
#define qpss _qpss()
#define sqss _sqss()
#define tqss _tqss()
#define pqss _pqss()
#define qqss _qqss()
#define ssts _ssts()
#define tsts _tsts()
#define psts _psts()
#define qsts _qsts()
#define stts _stts()
#define ttts _ttts()
#define ptts _ptts()
#define qtts _qtts()
#define spts _spts()
#define tpts _tpts()
#define ppts _ppts()
#define qpts _qpts()
#define sqts _sqts()
#define tqts _tqts()
#define pqts _pqts()
#define qqts _qqts()
#define ssps _ssps()
#define tsps _tsps()
#define psps _psps()
#define qsps _qsps()
#define stps _stps()
#define ttps _ttps()
#define ptps _ptps()
#define qtps _qtps()
#define spps _spps()
#define tpps _tpps()
#define ppps _ppps()
#define qpps _qpps()
#define sqps _sqps()
#define tqps _tqps()
#define pqps _pqps()
#define qqps _qqps()
#define ssqs _ssqs()
#define tsqs _tsqs()
#define psqs _psqs()
#define qsqs _qsqs()
#define stqs _stqs()
#define ttqs _ttqs()
#define ptqs _ptqs()
#define qtqs _qtqs()
#define spqs _spqs()
#define tpqs _tpqs()
#define ppqs _ppqs()
#define qpqs _qpqs()
#define sqqs _sqqs()
#define tqqs _tqqs()
#define pqqs _pqqs()
#define qqqs _qqqs()
#define ssst _ssst()
#define tsst _tsst()
#define psst _psst()
#define qsst _qsst()
#define stst _stst()
#define ttst _ttst()
#define ptst _ptst()
#define qtst _qtst()
#define spst _spst()
#define tpst _tpst()
#define ppst _ppst()
#define qpst _qpst()
#define sqst _sqst()
#define tqst _tqst()
#define pqst _pqst()
#define qqst _qqst()
#define sstt _sstt()
#define tstt _tstt()
#define pstt _pstt()
#define qstt _qstt()
#define sttt _sttt()
#define tttt _tttt()
#define pttt _pttt()
#define qttt _qttt()
#define sptt _sptt()
#define tptt _tptt()
#define pptt _pptt()
#define qptt _qptt()
#define sqtt _sqtt()
#define tqtt _tqtt()
#define pqtt _pqtt()
#define qqtt _qqtt()
#define sspt _sspt()
#define tspt _tspt()
#define pspt _pspt()
#define qspt _qspt()
#define stpt _stpt()
#define ttpt _ttpt()
#define ptpt _ptpt()
#define qtpt _qtpt()
#define sppt _sppt()
#define tppt _tppt()
#define pppt _pppt()
#define qppt _qppt()
#define sqpt _sqpt()
#define tqpt _tqpt()
#define pqpt _pqpt()
#define qqpt _qqpt()
#define ssqt _ssqt()
#define tsqt _tsqt()
#define psqt _psqt()
#define qsqt _qsqt()
#define stqt _stqt()
#define ttqt _ttqt()
#define ptqt _ptqt()
#define qtqt _qtqt()
#define spqt _spqt()
#define tpqt _tpqt()
#define ppqt _ppqt()
#define qpqt _qpqt()
#define sqqt _sqqt()
#define tqqt _tqqt()
#define pqqt _pqqt()
#define qqqt _qqqt()
#define sssp _sssp()
#define tssp _tssp()
#define pssp _pssp()
#define qssp _qssp()
#define stsp _stsp()
#define ttsp _ttsp()
#define ptsp _ptsp()
#define qtsp _qtsp()
#define spsp _spsp()
#define tpsp _tpsp()
#define ppsp _ppsp()
#define qpsp _qpsp()
#define sqsp _sqsp()
#define tqsp _tqsp()
#define pqsp _pqsp()
#define qqsp _qqsp()
#define sstp _sstp()
#define tstp _tstp()
#define pstp _pstp()
#define qstp _qstp()
#define sttp _sttp()
#define tttp _tttp()
#define pttp _pttp()
#define qttp _qttp()
#define sptp _sptp()
#define tptp _tptp()
#define pptp _pptp()
#define qptp _qptp()
#define sqtp _sqtp()
#define tqtp _tqtp()
#define pqtp _pqtp()
#define qqtp _qqtp()
#define sspp _sspp()
#define tspp _tspp()
#define pspp _pspp()
#define qspp _qspp()
#define stpp _stpp()
#define ttpp _ttpp()
#define ptpp _ptpp()
#define qtpp _qtpp()
#define sppp _sppp()
#define tppp _tppp()
#define pppp _pppp()
#define qppp _qppp()
#define sqpp _sqpp()
#define tqpp _tqpp()
#define pqpp _pqpp()
#define qqpp _qqpp()
#define ssqp _ssqp()
#define tsqp _tsqp()
#define psqp _psqp()
#define qsqp _qsqp()
#define stqp _stqp()
#define ttqp _ttqp()
#define ptqp _ptqp()
#define qtqp _qtqp()
#define spqp _spqp()
#define tpqp _tpqp()
#define ppqp _ppqp()
#define qpqp _qpqp()
#define sqqp _sqqp()
#define tqqp _tqqp()
#define pqqp _pqqp()
#define qqqp _qqqp()
#define sssq _sssq()
#define tssq _tssq()
#define pssq _pssq()
#define qssq _qssq()
#define stsq _stsq()
#define ttsq _ttsq()
#define ptsq _ptsq()
#define qtsq _qtsq()
#define spsq _spsq()
#define tpsq _tpsq()
#define ppsq _ppsq()
#define qpsq _qpsq()
#define sqsq _sqsq()
#define tqsq _tqsq()
#define pqsq _pqsq()
#define qqsq _qqsq()
#define sstq _sstq()
#define tstq _tstq()
#define pstq _pstq()
#define qstq _qstq()
#define sttq _sttq()
#define tttq _tttq()
#define pttq _pttq()
#define qttq _qttq()
#define sptq _sptq()
#define tptq _tptq()
#define pptq _pptq()
#define qptq _qptq()
#define sqtq _sqtq()
#define tqtq _tqtq()
#define pqtq _pqtq()
#define qqtq _qqtq()
#define sspq _sspq()
#define tspq _tspq()
#define pspq _pspq()
#define qspq _qspq()
#define stpq _stpq()
#define ttpq _ttpq()
#define ptpq _ptpq()
#define qtpq _qtpq()
#define sppq _sppq()
#define tppq _tppq()
#define pppq _pppq()
#define qppq _qppq()
#define sqpq _sqpq()
#define tqpq _tqpq()
#define pqpq _pqpq()
#define qqpq _qqpq()
#define ssqq _ssqq()
#define tsqq _tsqq()
#define psqq _psqq()
#define qsqq _qsqq()
#define stqq _stqq()
#define ttqq _ttqq()
#define ptqq _ptqq()
#define qtqq _qtqq()
#define spqq _spqq()
#define tpqq _tpqq()
#define ppqq _ppqq()
#define qpqq _qpqq()
#define sqqq _sqqq()
#define tqqq _tqqq()
#define pqqq _pqqq()
#define qqqq _qqqq()
*/

#endif//__swizzle_h__
