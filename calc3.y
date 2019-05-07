%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "calc3.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;

/* prototypes */
nodeType *opr(int oper, int nops, ...);
nodeType *id(int i);
nodeType *con(int value);
void freeNode(nodeType *p);
int ex(nodeType *p);
int yylex(void);

FILE * yyin; // input file for lex

void yyerror(string s);
int sym[26];                    /* symbol table */


struct IDENTIFIERInfo
{
	int type;									//int,double,char,bool,string
	int initialized;
	int isConst;
};

map <int,map <string,IDENTIFIERInfo> >symbolTable;
int scope_level=1;
IDENTIFIERInfo GetIdentifier(string s);
void newIdentifier(string s,int identfierType,int assignType,int isConst);
void updateIdentifier(string s,int assignType);
void print_identifer();
findIdenScope();

%}

%union {
    int iValue;                 /* integer value */
    char sIndex;                /* symbol table index */
    nodeType *nPtr;             /* node pointer */
};

%token <iValue> INTEGER CONST INT_TYPE FLOAT_TYPE STRING_TYPE 
%token <sIndex> VARIABLE STRING
%token WHILE IF PRINT DO_WHILE
%nonassoc IFX
%nonassoc ELSE

%left GE LE EQ NE '>' '<'
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS

%type <nPtr> stmt expr stmt_list

%%

program:
        function                { exit(0); }
        ;

function:
          function stmt         { ex($2); freeNode($2); }
        | /* NULL */
        ;

stmt:
          ';'                            { $$ = opr(';', 2, NULL, NULL); }
        | PRINT expr ';'                 { $$ = opr(PRINT, 1, $2); }
        | VARIABLE '=' expr ';'          { $$ = opr('=', 2, id($1), $3); }
        |TYPE VARIABLE	';'				 { newIdentifier($2, $1, -1, 0); //0 means not constant}
        |TYPE VARIABLE '=' expr ';'      { $$ = opr('=', 2, id($2), $4); 
											/*newIdentifier($2, $1, );//TODOOOOO*/}
        |CONST TYPE VARIABLE '=' INTEGER ';'	 { $$ = opr('=', 2, id($2), $4); } 
        |TYPE VARIABLE '=' INTEGER ';'	 { $$ = opr('=', 2, id($2), $4); }		
        | WHILE '(' expr ')' stmt        { $$ = opr(WHILE, 2, $3, $5); }
        | IF '(' expr ')' stmt %prec IFX { $$ = opr(IF, 2, $3, $5); }
        | IF '(' expr ')' stmt ELSE stmt { $$ = opr(IF, 3, $3, $5, $7); }
        | '{' stmt_list '}'              { $$ = $2; }
		| DO '{' stmt_list '}' WHILE '(' expr ')' { $$ = opr(DO_WHILE, 2, $7, $3); } 
        ;
TYPE:
		INT_TYPE						{$$ = $1;}
		|FLOAT_TYPE						{$$ = $1;}
		|STRING_TYPE					{$$ = $1;}
		|BOOL_TYPE						{$$ = $1;}
stmt_list:
          stmt                  { $$ = $1; }
        | stmt_list stmt        { $$ = opr(';', 2, $1, $2); }
        ;

expr:
          INTEGER               { $$ = con($1); }
        | VARIABLE              { $$ = id($1); }
		| BOOL
        | STRING 				{ $$ = $1;}

        | '-' expr %prec UMINUS { $$ = opr(UMINUS, 1, $2); }
        | expr '+' expr         { $$ = opr('+', 2, $1, $3); }
        | expr '-' expr         { $$ = opr('-', 2, $1, $3); }
        | expr '*' expr         { $$ = opr('*', 2, $1, $3); }
        | expr '/' expr         { $$ = opr('/', 2, $1, $3); }
        | expr '<' expr         { $$ = opr('<', 2, $1, $3); }
        | expr '>' expr         { $$ = opr('>', 2, $1, $3); }
        | expr GE expr          { $$ = opr(GE, 2, $1, $3); }
        | expr LE expr          { $$ = opr(LE, 2, $1, $3); }
        | expr NE expr          { $$ = opr(NE, 2, $1, $3); }
        | expr EQ expr          { $$ = opr(EQ, 2, $1, $3); }
        | '(' expr ')'          { $$ = $2; }
        ;

%%




int findIdenScope(string name)
{
	for(int i=1;i<=scope_level;i++)
	{
		if (symbolTable[i].find(name) != symbolTable[i].end())
			return i;
	}
	return -1;
}

void newIdentifier(string name,int identfierType,int assignType,int isConst)
{
	
	map<int,string> types;
	types[INTVAL]="Integer";
	types[DOUBLEVAL]="Double";
	types[CHARVAL]="Char";
	types[BOOLVAL]="Bool";
	int IdentifierScope=findIdenScope(name);
	if ( IdentifierScope <=scope_level ) {
			//TODO LINE NUMBER
			cout<<"Error at Line , Identifier "<<name<<" defined before";
			exit(1);
	}
	
	if(assignType!=-1)
	{
		if((assignType==INTVAL&&identfierType==DOUBLEVAL)||identfierType==assignType)
		{	
			IDENTIFIERInfo x;
			x.type=identfierType;
			x.isInit=1;
			x.isConst=isConst;
			symbolTable[scope_level][name]=x;
			return;
		}
		cout<<"Error at Line "<<int(ceil(yylineno/2.00))<<": no type conversion from "<<types[assignType]<<" to "<<types[identfierType];
		exit(1);
		if(identfierType==INTVAL&&assignType==DOUBLEVAL){
			IDENTIFIERInfo x;
			x.type=identfierType;
			x.isInit=1;
			x.isConst=isConst;
			symbolTable[scope_level][name]=x;
			cout<<"Warrning at Line "<<int(ceil(yylineno/2.00))<<": Converstion from Double to int may cause lose of data";
			return;

		}
	}
	
			IDENTIFIERInfo x;
			x.type=identfierType;
			x.isInit=0;
			x.isConst=isConst;

	symbolTable[scope_level][name]=x;
}

void updateIdentifier(string name,int assignType)
{
	
	map<int,string> types;
	types[INTVAL]="Integer";
	types[DOUBLEVAL]="Double";
	types[CHARVAL]="Char";
	types[BOOLVAL]="Bool";
	types[STRINGVAL]="String";
	
	int IdentifierScope=findIdenScope(name);
	if ( IdentifierScope==-1 ) {
		cout<<"Error at Line "<<int(ceil(yylineno/2.00))<<": Identifier ("<<name<<") not declared";
		exit(1);
	}
	
	if(symbolTable[IdentifierScope][name].isConst==1)
	{
		cout<<"Error at Line "<<int(ceil(yylineno/2.00))<<": Identifier ("<<name<<") is constant and cannot change its value";
		exit(1);
	}
	int identfierType=symbolTable[IdentifierScope][name].type;
	if(identfierType==INTVAL&&assignType==DOUBLEVAL){
	cout<<"Warrning at Line "<<int(ceil(yylineno/2.00))<<": Converstion from Double to int may cause lose of data";
	return;
	}
	if((assignType==INTVAL&&identfierType==DOUBLEVAL)||identfierType==assignType)
	{	
		return;
	}
	cout<<"Error at Line "<<int(ceil(yylineno/2.00))<<": no type conversion from "<<types[assignType]<<" to "<<types[identfierType];
	exit(1);
	}








/*
nodeType * getString(string s)
{
	nodeType *p;
	string result = s;
	/*
	string result = "";
	for( int i = 1; i<s.size()-1; i++)
		result += s[i];
	*/
	p->type = typeId;
    p->str.value = result;

    return p;	
	//return result;
}
*/

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
    cout << s; /*check for log file laaaaaaaaaaaater*/
}

int main(void) {
    yyin = fopen("myProgram.txt", "r"); // The input file for lex, the default is stdin
    yyparse();
    fclose(yyin);
    return 0;
}
