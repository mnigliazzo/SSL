/* Qué: Parser.c
* Biblioteca creada para el parser (Analizador Sintáctico)
* Quién: Matias Nigliazzo
* Cuando: 20200913
*/
#include "Parser.h"
#include "Scanner.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
typedef enum
{
  PARSER_OPERADOR,
  PARSER_VARIABLE,
  PARSER_NUMERO,
  PARSER_RECHAZADO
} StateParser;

typedef enum
{
  NUMERO = 0,
  OPERADOR = 2,
  VARIABLE = 1,
  LBRACKET = 3,
  RBRACKET = 4
} Caracter;
int termino();
int factor();



void ErrorSintactico();

int flagError=0;

int expresion(void)
{
  int r=termino();
    //printf("%d",flagToken);
  switch (GetNextToken())
    {
    case Token_SUMA:
      
      Match(Token_SUMA);
      r=r+expresion();
      if (flagError)
        r=0;
      return r;
    case Token_MULTIPLICADOR:case Token_VARIABLE:case Token_NUMERO:case Token_LBRACKET:case Token_RBRACKET:
      if (flagError)
        r=0;
      return r;
    case FDT:
      if (flagError)
        r=0;
      return r;
    default:
      ErrorSintactico();
      return 0;
    }
}

int termino(){
  int r =factor();
  Token tok;
  tok=GetNextToken();
    switch (tok){    
      case Token_MULTIPLICADOR: 
 
        Match(Token_MULTIPLICADOR);
        r=r*termino();
        if (flagError)
          r=0;
        return r;
      case Token_SUMA:case Token_VARIABLE:case Token_NUMERO:case Token_LBRACKET:case Token_RBRACKET:
        if (flagError)
          r=0;
        return r;
      case FDT:
        if (flagError)
          r=0;
        return r;
      default:
        
        ErrorSintactico();
        return 0;
    }
}



int factor()
{
  int r;
  Token tok = GetNextToken();
  switch (tok)
  {
  case Token_VARIABLE:  
    Match(Token_VARIABLE);
    r=1;// cualquier variable representa el valor 1
    if (flagError)
      r=0;
    return r;
  case Token_NUMERO:
    Match(Token_NUMERO);
    r=atoi(val);
    if (flagError)
      r=0;
    return r;
  case Token_LBRACKET:
    
    Match(Token_LBRACKET);
    r=expresion();
    Match(Token_RBRACKET);
    if (flagError)
      r=0;
    return r;
  default:
    ErrorSintactico();
    return 0;
  }
}


void Match(Token t)
{
  if ( !(t == GetNextToken()))
     ErrorSintactico();
  flagToken = 0;
}


void ErrorSintactico()
{
  printf("Error Sintactico\n");
  flagError=1;
}


