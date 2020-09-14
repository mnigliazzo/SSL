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
  c=getchar();
  if (isFDT(c))
  {
    return FDT;
  }
  else if (isalpha(c))
  {
    leerTokenVariable();
    return Token_VARIABLE;
  }
  else if (isdigit(c))
  {
    leerTokenDigito();
    return Token_NUMERO;
  }
  else if (isMultiplication(c))
  {
    return Token_MULTIPLICADOR;
  }
  else if (isPlus(c))
  {
    return Token_SUMA;
  }
  else
  {
    errorLexico();
    return Token_INVALIDO;
  } 
}  

bool isMultiplication(const int c){
  if(c=='*')
    return true;
  return false;  
}

bool isPlus(const int c){
  if(c=='+')
    return true;
  return false;  
}

bool isFDT (const int c){
  if (c==EOF)
    return true;
  return false;
}
void leerTokenVariable(){
  int c;
  c=getchar();
  if (isFDT(c)){
    ungetc(c, stdin);
    return;
  }
  else if (isalpha(c))
    leerTokenVariable();
  else if (isdigit(c))
    leerTokenVariable();
  else{
    ungetc(c, stdin);
    return;
  }
}

void leerTokenDigito(){
  int c;
  c=getchar();
  if (isFDT(c)){
    ungetc(c, stdin);
    return;
  }
  else if (isdigit(c))
    leerTokenDigito();
  else{
    ungetc(c, stdin);
    return;
  }
}
  

void errorLexico(){
  printf("Error Lexico\n");
}