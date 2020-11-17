%{
#include <stdio.h>
#include <string.h>
#include "Scanner.h"


void errorLexico();

int GetNextToken();

int fileno( FILE * stream );
%}
ID [a-zA-Z_][a-zA-Z0-9_]*
%option noyywrap
%%

[0-9]+    {yylval.intVal=atoi(yytext);return Token_NUMERO;}
\(        return Token_LBRACKET;
\)        return Token_RBRACKET;
\*        return Token_MULTIPLICADOR;
\+        return Token_SUMA;
\$        return Token_CALCULO;
\=        return Token_ASIGNACION;
{ID}      {strcpy(yylval.strVal, yytext);return Token_VARIABLE;}
<<EOF>>   return FDT;
[ ]+ ;
.         {
            errorLexico();
            return Token_ERRORLEXICO;
          }

%%


/* Qué: Scanner.c
* Biblioteca creada para scanner (Analizador Léxico)
* Quién: Matias Nigliazzo
* Cuando: 20200913
*/


int GetNextToken()
{
  return yylex();
}

void errorLexico()
{
  printf("Error Lexico\n");
}