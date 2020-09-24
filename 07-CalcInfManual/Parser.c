/* Qué: Parser.c
* Biblioteca creada para el parser (Analizador Sintáctico)
* Quién: Matias Nigliazzo
* Cuando: 20200913
*/
#include "Parser.h"
#include "Scanner.h"
#include <stdbool.h>
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
void termino();
void factor();



void ErrorSintactico();

void expresion(void)
{
  termino();
    //printf("%d",flagToken);
  switch (GetNextToken())
    {
    case Token_SUMA:
      
      Match(Token_SUMA);

      expresion();
      return;
    case Token_MULTIPLICADOR:case Token_VARIABLE:case Token_NUMERO:case Token_LBRACKET:case Token_RBRACKET:
        return;
    case FDT:
    //flagToken=0; 
      return;
    default:
      ErrorSintactico();
      break;
    }
}

void termino(){
  factor();
  Token tok;
  tok=GetNextToken();
    switch (tok){    
      case Token_MULTIPLICADOR: 
 
        Match(Token_MULTIPLICADOR);
        termino();
   
        break;
      case Token_SUMA:case Token_VARIABLE:case Token_NUMERO:case Token_LBRACKET:case Token_RBRACKET:
        return;
      case FDT:
        return;
      default:
        
        ErrorSintactico();
        return;
    }
}



void factor()
{
  Token tok = GetNextToken();
  switch (tok)
  {
  case Token_VARIABLE:  
    Match(Token_VARIABLE);
    break;
  case Token_NUMERO: /* <sentencia> -> LEER ( <listaIdentificadores> ); */

    Match(Token_NUMERO);
    break;
  case Token_LBRACKET: /* <sentencia> -> ESCRIBIR (<listaExpresiones>); */
    
    Match(Token_LBRACKET);
    expresion();
    Match(Token_RBRACKET);
    break;
  default:
    ErrorSintactico();
    break;
  }
}


void Match(Token t)
{
  if ( !(t == GetNextToken()) )
     ErrorSintactico();
  flagToken = 0;

}


// void repararErrorSintactico();

// void repararErrorSintactico(){

// }


void ErrorSintactico()
{
  printf("Error Sintactico\n");
}


