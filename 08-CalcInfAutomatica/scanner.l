%{
#include <stdio.h>
#include <string.h>
#include "Scanner.h"
#include <stdbool.h>
#include <ctype.h>

static int sp = 0;
void errorLexico();
int flagToken = 0;
char val[MAXVAL];
Token tokenActual;
Token GetNextToken();
int fileno( FILE * stream );
%}

%option noyywrap
%%

[0-9]+ {
          strcpy(val,yytext);
          return (Token_NUMERO);
          }
\( {

          strcpy(val,yytext);
          return Token_LBRACKET;
          }
\) {
          strcpy(val,yytext);
          return Token_RBRACKET;
          }
\* {
          strcpy(val,yytext);
          return Token_MULTIPLICADOR;
          }
\+ {
          strcpy(val,yytext);
          return Token_SUMA;
          }
\$ {
          strcpy(val,yytext);
          return Token_CALCULO;
          }
\= {
          strcpy(val,yytext);
          return Token_ASIGNACION;
          }
[a-zA-Z_][a-zA-Z0-9_]* {
          strcpy(val,yytext);
          return Token_VARIABLE;
          }
<<EOF>> { return FDT; }
[ ]+ ;
. {errorLexico();return Token_ERRORLEXICO;}

%%


/* Qué: Scanner.c
* Biblioteca creada para scanner (Analizador Léxico)
* Quién: Matias Nigliazzo
* Cuando: 20200913
*/


Token GetNextToken()
{

  if (!flagToken) //si es 0
  {

    tokenActual = yylex();
    if (tokenActual == Token_ERRORLEXICO)
      errorLexico();
    flagToken = 1;
  }
  return tokenActual;
}

void errorLexico()
{
  printf("Error Lexico\n");
}