#define INTEGER 257
#define CONST 258
#define INT_TYPE 259
#define FLOAT_TYPE 260
#define STRING_TYPE 261
#define VARIABLE 262
#define STRING 263
#define WHILE 264
#define IF 265
#define PRINT 266
#define IFX 267
#define ELSE 268
#define GE 269
#define LE 270
#define EQ 271
#define NE 272
#define UMINUS 273
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
    int iValue;                 /* integer value */
    char sIndex;                /* symbol table index */
    nodeType *nPtr;             /* node pointer */
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
