/* Qué: Calc.c
* Pueba de Calculadora infija Construnccion manual
* Quién: Matias Nigliazzo
* Cuando: 20200913
*/

#include <stdio.h>

#include "Parser.h"



int main(void)
{
  switch (parser()){
    case ACEPTADO:
      printf("La expresion es valida");
      break;
    case RECHAZADO:
      printf("La expresion no es valida");
      break;
    default:
      printf("Error");
      break;
  }
}
