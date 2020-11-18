/* Qué: Scanner.h
* Prototipos para el scanner
* Quién: Matias Nigliazzo
* Cuando: 20200913
*/
#pragma once
#include "Token.h"

extern int flagToken;
TipoToken GetNextToken(); // Devuelve el tipo de token que encuentra
extern TipoToken tokenActual;
