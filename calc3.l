%{
#include <stdlib.h>
#include "calc3.h"
#include "y.tab.h"
#include <string>
using namespace std;

void yyerror(string);
%}

%%

">="            return GE;
"<="            return LE;
"=="            return EQ;
"!="            return NE;
"&&"			return AND;
"||"			return OR;
"!"				return NOT;
"do"			return DO_WHILE;
"While"         return WHILE;
"if"            return IF;
"else"          return ELSE;
"print"         return PRINT;
"const"         return CONST; ///////////////
"int"           return INT_TYPE; /////////////////
"float"         return FLOAT_TYPE; /////////////////
"string"        return STRING_TYPE; ////////////////////
"bool"			return BOOL;
"true"			return TRUE;
"false"			return FALSE;
"break"			return BREAK;


[ \t\n]+        ;       /* ignore whitespace */
[0-9]+[.][0-9]+			{
							yylval.iValue = stof(yytext);
							return FLOAT;
						}
						
[a-zA-Z][a-zA-Z0-9]*       { 
                               yylval.sIndex = *yytext - 'a';
                               return VARIABLE;
                            }

["][a-zA-Z0-9 ]*["]      	{ 
                               yylval.sIndex = *yytext - 'a';
                               return STRING;
                            }

0           {
                yylval.iValue = atoi(yytext);
                return INTEGER;
            }

[1-9][0-9]* {
                yylval.iValue = atoi(yytext);
                return INTEGER;
            }

[-()<>=+*/;{}.] {
                return *yytext;
             }



.               yyerror("Unknown character");
%%
int yywrap(void) {
    return 1;
}
