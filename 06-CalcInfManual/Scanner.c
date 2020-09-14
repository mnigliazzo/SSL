/* Qué: Scanner.c
* Biblioteca creada para scanner (Analizador Léxico)
* Quién: Matias Nigliazzo
* Cuando: 20200913
*/
#include <stdio.h>
#include "Scanner.h"

Token GetNextToken()
{
  int c;
  StateScanner state = INICIAL;
  Token tokenResultado = FDT;
  while ((c = getchar()) != EOF)
  {
    switch (state)
    {
    case INICIAL:
      if (esOperador(c))
      {
        state = OPERADOR;
        tokenResultado = Token_OPERADOR;
      }
      else if (esNumero(c))
      {
        state = NUMERO;
        tokenResultado = Token_NUMERO;
      }
      else if (esVariable(c))
      {
        state = VARIABLE;
        tokenResultado = Token_VARIABLE;
      }
      else
      {
        state = RECHAZO;
        errorLexico();
        tokenResultado = Token_INVALIDO;
      }
      break;
    case OPERADOR:
      tokenResultado = Token_OPERADOR;
    case NUMERO:
      if (esOperador(c))
      {
        state = OPERADOR;
        tokenResultado = Token_OPERADOR;
      }
      else if (esNumero(c))
      {
        state = NUMERO;
        tokenResultado = Token_NUMERO;
      }
      else if (esVariable(c))
      {
        state = VARIABLE;
        tokenResultado = Token_VARIABLE;
      }
      else
      {
        state = RECHAZO;
        errorLexico();
        tokenResultado = Token_INVALIDO;
      }
      break;
    case VARIABLE:
      if (esOperador(c))
      {
        state = OPERADOR;
        return Token_OPERADOR;
      }
      else if (esNumero(c))
      {
        state = NUMERO;
        tokenResultado = Token_NUMERO;
      }
      else if (esVariable(c))
      {
        state = VARIABLE;
        tokenResultado = Token_VARIABLE;
      }
      else
      {
        state = RECHAZO;
        errorLexico();
        tokenResultado = Token_INVALIDO;
      }
      break;
    case RECHAZO:
      errorLexico();
      tokenResultado = Token_INVALIDO;
    }
  }
  return tokenResultado;
}

int esNumero(const char c){
  switch (c){
    case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
      return 1;
      break;
    default:
      return 0;
      break;
  }
}

int esVariable(const char c){
  switch (c){
    case 'a':case 'b':case 'c':case 'd':case 'e':case 'f':case 'g':case 'h':case 'i':case 'j':case 'k':case 'l':case 'm':case 'n':case 'o':case 'p':case 'q':case 'r':case 's':case 't':case 'u':case 'v':case 'w':case 'x':case 'y':case 'z':
      return 1;
      break;
    default:
      return 0;
      break;
  }
}

int esOperador(const char c){
  switch (c){
    case '+':case '*':
      return 1;
      break;
    default:
      return 0;
      break;
  }
}

void errorLexico(){
  printf("Error Lexico\n");
}