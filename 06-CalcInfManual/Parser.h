/* Qué: Parser.h
* Prototipos para el parser
* Quién: Matias Nigliazzo
* Cuando: 20200913
*/

typedef enum
{
  ACEPTADO,
  RECHAZADO
} Resultado;

typedef enum
{
  PARSER_INICIAL,
  PARSER_OPERADOR,
  PARSER_VARIABLE,
  PARSER_NUMERO,
  PARSER_RECHAZADO
} StateParser;

Resultado parser();