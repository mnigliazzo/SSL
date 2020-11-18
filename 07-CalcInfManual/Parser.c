/* Qué: Parser.c
* Biblioteca creada para el parser (Analizador Sintáctico)
* Quién: Matias Nigliazzo
* Cuando: 20200913
*/
#include "Parser.h"
#include "Scanner.h"
#include "TablaSimbolos.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int resultado=0;

void parser();
void listaSentencia();
void sentencia();
int expresion();
int termino();
int factor();
void programa();
void Match();



void ErrorSintactico();

int flagError=0;

void parser (void){
  programa();
}

void programa(){
  listaSentencia();
  Match(FDT);
}


void listaSentencia(){
  int r ; 
  sentencia();
  while (1) {
    switch (GetNextToken()) {
      case Token_VARIABLE:case Token_CALCULO:
        sentencia();
        break;
      default:
        return;
    }
  }
}

void sentencia(){
  char variable[100];
  int numero;
  switch (GetNextToken())
  {
  case Token_CALCULO:
        Match(Token_CALCULO);
        resultado=expresion();
        if (flagError)
          resultado=0;
        printf("\nResultado: %d",resultado);
        return;
  case Token_VARIABLE:
    Match(Token_VARIABLE);
    strcpy(variable,lexema);
    Match(Token_ASIGNACION);
    Match(Token_NUMERO);
    numero=atoi(lexema);
    agregarTablaSimbolos(variable,numero);
    return;
  default:
    return;
  }
}

int expresion(void)
{
  int r=termino();
  switch (GetNextToken())
    {
    case Token_SUMA:   
      Match(Token_SUMA);
      r=r+ expresion();
      return r;
    default:  
      return r;
    }
}

int termino(){
  int r =factor();
  TipoToken tok;
  tok=GetNextToken();
    switch (tok){    
      case Token_MULTIPLICADOR: 
        Match(Token_MULTIPLICADOR);
        r=r*termino();
        return r;
      default:
        return r;
    }
}



int factor()
{
  int r;
  TipoToken tok = GetNextToken();
  switch (tok)
  {
  case Token_VARIABLE:  
    Match(Token_VARIABLE);
    r=buscarTablaSimbolos(lexema);
    return r;
  case Token_NUMERO:
    Match(Token_NUMERO);
    r=atoi(lexema);
    return r;
  case Token_LBRACKET:
    
    Match(Token_LBRACKET);
    r=expresion();
    Match(Token_RBRACKET);
    return r;
  default:
    ErrorSintactico();     
    return r;
  }
}


void Match(TipoToken t)
{
  if ( !(t == GetNextToken())) // si el proximo token no coincide con el que deberia coincidir da error Sintactico
     ErrorSintactico();
  flagToken = 0; // permite que getNextToken siga capturando tokens
}


void ErrorSintactico()
{
  printf("Error Sintactico\n");
  resultado=0;
  flagError=1;
}

