/* Qué: Parser.h
* Prototipos para el parser
* Quién: Matias Nigliazzo
* Cuando: 20200913
*/
#ifndef parser_h_
#define parser_h_
#include "Scanner.h"

void parser(void);
extern int resultado;

void Match(Token);

#endif