%{
#include <stdio.h>
#include <string.h>
#include "Scanner.h"
#include <stdbool.h>
#include <ctype.h>

void errorLexico();
int flagToken = 0;
char lexema[MAXVAL];
TipoToken tokenActual;
TipoToken GetNextToken();
int fileno( FILE * stream ); //defino impricitamente el prototipo ya que al no ser un funcion estandard de c, y scanner hace uso de esta funcion (devuelve el descriptor del archivo)
%}

%option noyywrap
%%

[0-9]+ {
          strcpy(lexema,yytext);
          return (Token_NUMERO);
          }
\( {

          strcpy(lexema,yytext);
          return Token_LBRACKET;
          }
\) {
          strcpy(lexema,yytext);
          return Token_RBRACKET;
          }
\* {
          strcpy(lexema,yytext);
          return Token_MULTIPLICADOR;
          }
\+ {
          strcpy(lexema,yytext);
          return Token_SUMA;
          }
\$ {
          strcpy(lexema,yytext);
          return Token_CALCULO;
          }
\= {
          strcpy(lexema,yytext);
          return Token_ASIGNACION;
          }
[a-zA-Z_][a-zA-Z0-9_]* {
          strcpy(lexema,yytext);
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


TipoToken GetNextToken()
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