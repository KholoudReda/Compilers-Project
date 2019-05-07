/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "calc3.y"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "calc3.h"
#include <iostream>
#include <string>
using namespace std;

/* prototypes */
nodeType *opr(int oper, int nops, ...);
nodeType *id(int i);
nodeType *con(int value);
void freeNode(nodeType *p);
int ex(nodeType *p);
int yylex(void);

FILE * yyin; /* input file for lex*/

void yyerror(string s);
int sym[26];                    /* symbol table */
#line 24 "calc3.y"
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
#line 55 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

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
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    4,    4,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    3,    3,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,
};
static const YYINT yylen[] = {                            2,
    1,    2,    0,    1,    2,    3,    4,    5,    5,    5,
    5,    5,    5,    7,    3,    1,    2,    1,    1,    1,
    2,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,
};
static const YYINT yydefred[] = {                         3,
    0,    0,   18,    0,    0,    0,    0,    0,   20,    0,
    0,    0,    0,    4,    0,    0,    2,    0,    0,    0,
    0,    0,    0,    0,    0,   19,    0,   21,    0,   16,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    5,    0,    0,    0,    0,    0,    0,    0,    6,
   32,   15,   17,    0,    0,    0,    0,    0,    0,    0,
    0,   24,   25,    0,    0,    0,    0,    7,    0,    0,
   11,    8,    9,   10,   12,    0,    0,   14,
};
static const YYINT yydgoto[] = {                          1,
   17,   18,   31,    2,
};
static const YYINT yysindex[] = {                         0,
    0,  176,    0, -255, -250, -248, -237,  -29,    0,   -7,
   -6,  -21,  -21,    0,  -21,  176,    0,   58,  -23,  -22,
  -18,  -13,  -21,  -21,  -21,    0,   68,    0,  -39,    0,
  164,  -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,  -21,
  -21,    0, -221,  -21,  -21,  -21,   89,  -32,  -25,    0,
    0,    0,    0,  -16,  -16,  -16,  -16,  -16,  -16,  -42,
  -42,    0,    0,   -8,   95,  116,  122,    0,  176,  176,
    0,    0,    0,    0,    0, -216,  176,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,   53,    0,    0,    0,    0,    0,  143,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    9,   13,   21,   26,   33,   37,   -1,
    4,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    1,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   39,  309,    0,    0,
};
#define YYTABLESIZE 442
static const YYINT yytable[] = {                         40,
   13,   51,   40,   38,   41,   39,   19,   41,   69,   40,
   38,   20,   39,   21,   41,   70,   40,   38,   15,   39,
   37,   41,   36,   13,   22,   40,   38,   37,   39,   36,
   41,   23,   24,   25,   37,   64,   36,   43,   44,   22,
   13,   22,   45,   22,   23,   13,   23,   46,   23,   28,
   71,   77,    1,   29,   30,    0,    0,   22,   22,   13,
   22,   31,   23,   23,    0,   23,   30,   28,   28,   53,
   28,   29,   29,   27,   29,    0,    0,   26,    0,   31,
   31,    0,   31,    0,   30,   30,    0,   30,    0,    0,
    0,   27,   27,    0,   27,   26,   26,    0,   26,   40,
   38,    0,   39,    0,   41,    0,    0,   75,   76,   40,
   38,    0,   39,    0,   41,   78,   42,   37,    0,   36,
    0,    0,    0,   13,    0,   13,   50,   37,    0,   36,
   40,   38,    0,   39,    0,   41,   40,   38,    0,   39,
    0,   41,    0,    0,    0,    0,    0,   68,   37,    0,
   36,    0,    0,   72,   37,    0,   36,   40,   38,    0,
   39,    0,   41,   40,   38,    0,   39,    0,   41,    0,
    0,    0,    0,    0,   73,   37,    0,   36,    0,    0,
   74,   37,    0,   36,   19,   19,    0,   19,    0,   19,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   19,   19,   15,   19,    0,    0,    0,   13,    0,
    0,    0,    0,    0,    0,   15,    0,    0,    0,    0,
   13,    0,   14,    0,    0,    0,    0,    0,    0,   32,
   33,   34,   35,    0,   14,    3,   32,   33,   34,   35,
   26,    9,    0,   32,   33,   34,   35,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   13,   13,   13,
   13,   13,   13,   13,   13,   13,   13,   22,   22,   22,
   22,    0,   23,   23,   23,   23,    0,   28,   28,   28,
   28,   29,   29,   29,   29,    0,   16,    0,   52,   31,
   31,   31,   31,    0,   30,   30,   30,   30,   16,    0,
    0,   27,   27,   27,   27,   26,   26,   26,   26,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   27,   28,    0,   29,    0,    0,   32,   33,   34,   35,
    0,   47,   48,   49,    0,    0,   32,   33,   34,   35,
   54,   55,   56,   57,   58,   59,   60,   61,   62,   63,
    0,    0,   65,   66,   67,    0,    0,   32,   33,   34,
   35,    0,    0,   32,   33,   34,   35,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   32,   33,   34,   35,    0,    0,
   32,   33,   34,   35,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   19,   19,   19,   19,    0,    0,    0,    0,    0,
    3,    4,    5,    6,    7,    8,    9,   10,   11,   12,
    0,    0,    3,    4,    5,    6,    7,    8,    9,   10,
   11,   12,
};
static const YYINT yycheck[] = {                         42,
    0,   41,   42,   43,   47,   45,  262,   47,   41,   42,
   43,  262,   45,  262,   47,   41,   42,   43,   40,   45,
   60,   47,   62,   45,  262,   42,   43,   60,   45,   62,
   47,   61,   40,   40,   60,  257,   62,   61,   61,   41,
   40,   43,   61,   45,   41,   45,   43,   61,   45,   41,
   59,  268,    0,   41,   16,   -1,   -1,   59,   60,   59,
   62,   41,   59,   60,   -1,   62,   41,   59,   60,   31,
   62,   59,   60,   41,   62,   -1,   -1,   41,   -1,   59,
   60,   -1,   62,   -1,   59,   60,   -1,   62,   -1,   -1,
   -1,   59,   60,   -1,   62,   59,   60,   -1,   62,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,   69,   70,   42,
   43,   -1,   45,   -1,   47,   77,   59,   60,   -1,   62,
   -1,   -1,   -1,  123,   -1,  125,   59,   60,   -1,   62,
   42,   43,   -1,   45,   -1,   47,   42,   43,   -1,   45,
   -1,   47,   -1,   -1,   -1,   -1,   -1,   59,   60,   -1,
   62,   -1,   -1,   59,   60,   -1,   62,   42,   43,   -1,
   45,   -1,   47,   42,   43,   -1,   45,   -1,   47,   -1,
   -1,   -1,   -1,   -1,   59,   60,   -1,   62,   -1,   -1,
   59,   60,   -1,   62,   42,   43,   -1,   45,   -1,   47,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   59,   60,   40,   62,   -1,   -1,   -1,   45,   -1,
   -1,   -1,   -1,   -1,   -1,   40,   -1,   -1,   -1,   -1,
   45,   -1,   59,   -1,   -1,   -1,   -1,   -1,   -1,  269,
  270,  271,  272,   -1,   59,  257,  269,  270,  271,  272,
  262,  263,   -1,  269,  270,  271,  272,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,
  260,  261,  262,  263,  264,  265,  266,  269,  270,  271,
  272,   -1,  269,  270,  271,  272,   -1,  269,  270,  271,
  272,  269,  270,  271,  272,   -1,  123,   -1,  125,  269,
  270,  271,  272,   -1,  269,  270,  271,  272,  123,   -1,
   -1,  269,  270,  271,  272,  269,  270,  271,  272,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   12,   13,   -1,   15,   -1,   -1,  269,  270,  271,  272,
   -1,   23,   24,   25,   -1,   -1,  269,  270,  271,  272,
   32,   33,   34,   35,   36,   37,   38,   39,   40,   41,
   -1,   -1,   44,   45,   46,   -1,   -1,  269,  270,  271,
  272,   -1,   -1,  269,  270,  271,  272,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  269,  270,  271,  272,   -1,   -1,
  269,  270,  271,  272,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  269,  270,  271,  272,   -1,   -1,   -1,   -1,   -1,
  257,  258,  259,  260,  261,  262,  263,  264,  265,  266,
   -1,   -1,  257,  258,  259,  260,  261,  262,  263,  264,
  265,  266,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 273
#define YYUNDFTOKEN 280
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,"';'",
"'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,"INTEGER","CONST","INT_TYPE","FLOAT_TYPE","STRING_TYPE",
"VARIABLE","STRING","WHILE","IF","PRINT","IFX","ELSE","GE","LE","EQ","NE",
"UMINUS",0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : function",
"function : function stmt",
"function :",
"stmt : ';'",
"stmt : expr ';'",
"stmt : PRINT expr ';'",
"stmt : VARIABLE '=' expr ';'",
"stmt : INT_TYPE VARIABLE '=' expr ';'",
"stmt : FLOAT_TYPE VARIABLE '=' expr ';'",
"stmt : STRING_TYPE VARIABLE '=' expr ';'",
"stmt : CONST VARIABLE '=' INTEGER ';'",
"stmt : WHILE '(' expr ')' stmt",
"stmt : IF '(' expr ')' stmt",
"stmt : IF '(' expr ')' stmt ELSE stmt",
"stmt : '{' stmt_list '}'",
"stmt_list : stmt",
"stmt_list : stmt_list stmt",
"expr : INTEGER",
"expr : VARIABLE",
"expr : STRING",
"expr : '-' expr",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '<' expr",
"expr : expr '>' expr",
"expr : expr GE expr",
"expr : expr LE expr",
"expr : expr NE expr",
"expr : expr EQ expr",
"expr : '(' expr ')'",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 97 "calc3.y"

nodeType * getString(string s)
{
	nodeType *p;

	string result = "";
	for( int i = 1; i<s.size()-1; i++)
		result += s[i];

	p->type = typeId;
    p->id.i = result;

    return p;	
	//return result;
}

nodeType *con(int value) {
    nodeType *p;

    /* allocate node */
    if ((p = (nodeType*)malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeCon;
    p->con.value = value;

    return p;
}

nodeType *id(int i) {
    nodeType *p;

    /* allocate node */
    if ((p = (nodeType *)malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeId;
    p->id.i = i;

    return p;
}

nodeType *opr(int oper, int nops, ...) {
    va_list ap;
    nodeType *p;
    int i;

    /* allocate node, extending op array */
    if ((p = (nodeType *)malloc(sizeof(nodeType) + (nops-1) * sizeof(nodeType *))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeOpr;
    p->opr.oper = oper;
    p->opr.nops = nops;
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
        p->opr.op[i] = va_arg(ap, nodeType*);
    va_end(ap);
    return p;
}

void freeNode(nodeType *p) {
    int i;

    if (!p) return;
    if (p->type == typeOpr) {
        for (i = 0; i < p->opr.nops; i++)
            freeNode(p->opr.op[i]);
    }
    free (p);
}

void yyerror(string s) {
    cout << s; //check for log file laaaaaaaaaaaater
}

int main(void) {
    yyin = fopen("myProgram.txt", "r"); // The input file for lex, the default is stdin
    yyparse();
    fclose(yyin);
    return 0;
}
#line 428 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 46 "calc3.y"
	{ exit(0); }
break;
case 2:
#line 50 "calc3.y"
	{ ex(yystack.l_mark[0].nPtr); freeNode(yystack.l_mark[0].nPtr); }
break;
case 4:
#line 55 "calc3.y"
	{ yyval.nPtr = opr(';', 2, NULL, NULL); }
break;
case 5:
#line 56 "calc3.y"
	{ yyval.nPtr = yystack.l_mark[-1].nPtr; }
break;
case 6:
#line 57 "calc3.y"
	{ yyval.nPtr = opr(PRINT, 1, yystack.l_mark[-1].nPtr); }
break;
case 7:
#line 58 "calc3.y"
	{ yyval.nPtr = opr('=', 2, id(yystack.l_mark[-3].sIndex), yystack.l_mark[-1].nPtr); }
break;
case 8:
#line 60 "calc3.y"
	{ yyval.nPtr = opr('=', 2, id(yystack.l_mark[-3].sIndex), yystack.l_mark[-1].nPtr); }
break;
case 9:
#line 61 "calc3.y"
	{ yyval.nPtr = opr('=', 2, id(yystack.l_mark[-3].sIndex), yystack.l_mark[-1].nPtr); }
break;
case 10:
#line 62 "calc3.y"
	{ yyval.nPtr = opr('=', 2, id(yystack.l_mark[-3].sIndex), yystack.l_mark[-1].nPtr); }
break;
case 11:
#line 63 "calc3.y"
	{ yyval.nPtr = opr('=', 2, id(yystack.l_mark[-3].sIndex), yystack.l_mark[-1].iValue); }
break;
case 12:
#line 65 "calc3.y"
	{ yyval.nPtr = opr(WHILE, 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 13:
#line 66 "calc3.y"
	{ yyval.nPtr = opr(IF, 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 14:
#line 67 "calc3.y"
	{ yyval.nPtr = opr(IF, 3, yystack.l_mark[-4].nPtr, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 15:
#line 68 "calc3.y"
	{ yyval.nPtr = yystack.l_mark[-1].nPtr; }
break;
case 16:
#line 72 "calc3.y"
	{ yyval.nPtr = yystack.l_mark[0].nPtr; }
break;
case 17:
#line 73 "calc3.y"
	{ yyval.nPtr = opr(';', 2, yystack.l_mark[-1].nPtr, yystack.l_mark[0].nPtr); }
break;
case 18:
#line 77 "calc3.y"
	{ yyval.nPtr = con(yystack.l_mark[0].iValue); }
break;
case 19:
#line 78 "calc3.y"
	{ yyval.nPtr = id(yystack.l_mark[0].sIndex); }
break;
case 20:
#line 80 "calc3.y"
	{ yyval.nPtr = getString(yystack.l_mark[0].sIndex); }
break;
case 21:
#line 82 "calc3.y"
	{ yyval.nPtr = opr(UMINUS, 1, yystack.l_mark[0].nPtr); }
break;
case 22:
#line 83 "calc3.y"
	{ yyval.nPtr = opr('+', 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 23:
#line 84 "calc3.y"
	{ yyval.nPtr = opr('-', 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 24:
#line 85 "calc3.y"
	{ yyval.nPtr = opr('*', 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 25:
#line 86 "calc3.y"
	{ yyval.nPtr = opr('/', 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 26:
#line 87 "calc3.y"
	{ yyval.nPtr = opr('<', 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 27:
#line 88 "calc3.y"
	{ yyval.nPtr = opr('>', 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 28:
#line 89 "calc3.y"
	{ yyval.nPtr = opr(GE, 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 29:
#line 90 "calc3.y"
	{ yyval.nPtr = opr(LE, 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 30:
#line 91 "calc3.y"
	{ yyval.nPtr = opr(NE, 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 31:
#line 92 "calc3.y"
	{ yyval.nPtr = opr(EQ, 2, yystack.l_mark[-2].nPtr, yystack.l_mark[0].nPtr); }
break;
case 32:
#line 93 "calc3.y"
	{ yyval.nPtr = yystack.l_mark[-1].nPtr; }
break;
#line 754 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
