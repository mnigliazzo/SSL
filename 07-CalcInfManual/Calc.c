/* Qué: Calc.c
* Pueba de Calculadora infija Construnccion manual
* Quién: Matias Nigliazzo
* Cuando: 20200913
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Parser.h"



int main()
{
  parser();
  //printf("El resultado es: %d\n",parser());
  Match(FDT);

  printf("\nResultado: %d",resultado);

}
