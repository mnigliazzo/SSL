/* Qué: Parser.c
* Biblioteca creada para el parser (Analizador Sintáctico)
* Quién: Matias Nigliazzo
* Cuando: 20200913
*/
#include "Parser.h"
#include "Scanner.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char variable[MAXVAL];;
    int valor;
}Simbolos;

int resultado=0;
Simbolos TablaSimbolos[MAXVAL];
int id_TablaSimbolos=0;

void agregarTablaSimbolos(char [],int);
int buscarTablaSimbolos(char []);
void parser();
void listaSentencia();
void sentencia();
int expresion();
int termino();
int factor();



void ErrorSintactico();

int flagError=0;

void parser (void){
  return listaSentencia();
}

void listaSentencia(){
  int r ; 
  sentencia();
  while (1) {
    switch (GetNextToken()) {
      case Token_VARIABLE:
        sentencia();
        break;
      case Token_CALCULO:
        Match(Token_CALCULO);
        resultado=expresion();
        if (flagError)
          resultado=0;
        return;
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
  case Token_VARIABLE:

    Match(Token_VARIABLE);
    strcpy(variable,val);
    Match(Token_ASIGNACION);
    Match(Token_NUMERO);
    numero=atoi(val);
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
  Token tok;
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
  Token tok = GetNextToken();
  switch (tok)
  {
  case Token_VARIABLE:  
    Match(Token_VARIABLE);
    r=buscarTablaSimbolos(val);
    return r;
  case Token_NUMERO:
    Match(Token_NUMERO);
    r=atoi(val);
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


void Match(Token t)
{
  if ( !(t == GetNextToken()))
     ErrorSintactico();
  flagToken = 0;
}


void ErrorSintactico()
{
  printf("Error Sintactico\n");
  resultado=0;
  flagError=1;
}

void agregarTablaSimbolos(char nombre[MAXVAL],int valor){
  for(int i=0;i<id_TablaSimbolos;i++){
    if(strcmp(TablaSimbolos[i].variable,nombre)==0)
    {
      TablaSimbolos[i].valor=valor;
      return;
    }
  }
  strcpy(TablaSimbolos[id_TablaSimbolos].variable,nombre);
  TablaSimbolos[id_TablaSimbolos].valor=valor;
  id_TablaSimbolos++;
}


int buscarTablaSimbolos(char nombre[MAXVAL]){
  int valorRetorno;
  for(int i=0;i<id_TablaSimbolos;i++){
    if(strcmp(TablaSimbolos[i].variable,nombre)==0)
    {
      valorRetorno= TablaSimbolos[i].valor;     
      return valorRetorno;
    }
  }
  printf("\n************Variable No Declarada*****************\n");
  return 0;
}
