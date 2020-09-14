/* Qué: Parser.c
* Biblioteca creada para el parser (Analizador Sintáctico)
* Quién: Matias Nigliazzo
* Cuando: 20200913
*/
#include "Parser.h"
#include "Scanner.h"

Resultado parser()
{
  StateParser stateParser = PARSER_INICIAL;
  Token token;
  Resultado resultado;
  while ((token = GetNextToken()) != FDT)
  {

    switch (stateParser)
    {
    case PARSER_INICIAL:
      switch (token)
      {
      case Token_NUMERO:
        stateParser = PARSER_NUMERO;
        resultado = ACEPTADO;
        break;
      case Token_VARIABLE:
        stateParser = PARSER_VARIABLE;
        resultado = ACEPTADO;
        break;
      default:
        stateParser = PARSER_RECHAZADO;
        resultado = RECHAZADO;
        //return resultado;
        break;
      }
      break;
    case PARSER_VARIABLE:
    case PARSER_NUMERO:
      switch (token)
      {
      case Token_OPERADOR:
        stateParser = PARSER_OPERADOR;
        resultado = ACEPTADO;
        break;
      default:
        stateParser = PARSER_RECHAZADO;
        resultado = RECHAZADO;
        //return resultado;
        break;
      }
      break;
    case PARSER_OPERADOR:
      switch (token)
      {
      case Token_NUMERO:
        stateParser = PARSER_NUMERO;
        resultado = ACEPTADO;
        break;
      case Token_VARIABLE:
        stateParser = PARSER_VARIABLE;
        resultado = ACEPTADO;
        break;
      default:
        resultado = RECHAZADO;
        stateParser = PARSER_RECHAZADO;
        // return resultado;
        break;
      }
      break;

    default:
      //resultado=RECHAZADO;
      //return resultado;
      break;
    }
  }

  return resultado;
}