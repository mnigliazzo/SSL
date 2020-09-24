/* Qué: Parser.h
* Prototipos para el parser
* Quién: Matias Nigliazzo
* Cuando: 20200913
*/
#ifndef parser_h_
#define parser_h_
#include "Scanner.h"
// #include "stack.h"
// typedef enum
// {
//   ACEPTADO,
//   RECHAZADO
// } Resultado;



// typedef enum
// {
//   Q0,
//   Q1,
//   Q2,
//   RECHAZO
// } State;

// typedef enum
// {
//   P0=0,
//   R=1,
//   RR=2,
//   E=3
// } Pila;

// typedef struct
// {
//   State estado;
//   Pila cadpush; 
// } StructState;
int expresion(void);

void Match(Token);

#endif
