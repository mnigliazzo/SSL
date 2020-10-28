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
        //printf("otra variable");
        sentencia();
        break;
      case Token_CALCULO:
        Match(Token_CALCULO);
       // printf("calculo");
        resultado=expresion();
        if (flagError)
          resultado=0;
        return;
      default:
      //  printf(" es otra coas");
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
   // printf("%d",atoi(val));
   // printf("%s",val);
    agregarTablaSimbolos(variable,numero);
    return;
  default:
    //printf("no es sentencias");
    return;
  }
}

int expresion(void)
{
  int r=termino();
    //printf("%d",flagToken);
  switch (GetNextToken())
    {
    case Token_SUMA:
      
      Match(Token_SUMA);
      r=r+      expresion();
      //sumar();
      if (flagError)
        r=0;
      return r;
    case Token_MULTIPLICADOR:case Token_VARIABLE:case Token_NUMERO:case Token_LBRACKET:case Token_RBRACKET:
      if (flagError)
        r=0;
      return r;
    case FDT:
      if (flagError)
        r=0;
      return r;
    default:
  //    ErrorSintactico();
      r=0;
      return r;
    }
}

int termino(){
  int r =factor();
  while(1){
  Token tok;
  tok=GetNextToken();
    switch (tok){    
      case Token_MULTIPLICADOR: 
 
        Match(Token_MULTIPLICADOR);
        r=r*termino();
        //multiplicar();
        if (flagError)
          r=0;
        return r;
      case Token_SUMA:case Token_VARIABLE:case Token_NUMERO:case Token_LBRACKET:case Token_RBRACKET:
        if (flagError)
          r=0;
        return r;
      case FDT:
        if (flagError)
          r=0;
        return r;
      default:
        
       // ErrorSintactico();
        return r;
    }
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
  //  r=1;// cualquier variable representa el valor 1
    if (flagError)
      r=0;
    return r;
  case Token_NUMERO:
    Match(Token_NUMERO);
    r=atoi(val);
    if (flagError)
      r=0;
    return r;
  case Token_LBRACKET:
    
    Match(Token_LBRACKET);
    r=expresion();
    Match(Token_RBRACKET);
    if (flagError)
      r=0;
    return r;
  default:
   // ErrorSintactico();
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
  flagError=1;
}

void agregarTablaSimbolos(char nombre[MAXVAL],int valor){
  //printf("%s %d\n\n",nombre,2);
  for(int i=0;i<id_TablaSimbolos;i++){
    if(strcmp(TablaSimbolos[i].variable,nombre)==0)
    {
      TablaSimbolos[i].valor=valor;
      return;
    }
  }
  // printf("%s",TablaSimbolos[id_TablaSimbolos].variable);
  // printf("%d",TablaSimbolos[id_TablaSimbolos].valor); 
  strcpy(TablaSimbolos[id_TablaSimbolos].variable,nombre);
  TablaSimbolos[id_TablaSimbolos].valor=valor;
  // printf("%s",TablaSimbolos[id_TablaSimbolos].variable);
  // printf("%d",TablaSimbolos[id_TablaSimbolos].valor); 
  id_TablaSimbolos++;
}


int buscarTablaSimbolos(char nombre[MAXVAL]){
  int valorRetorno;
  for(int i=0;i<id_TablaSimbolos;i++){
    if(strcmp(TablaSimbolos[i].variable,nombre)==0)
    {
   //  printf("%s",TablaSimbolos[i].variable);
      valorRetorno= TablaSimbolos[i].valor;
   //   printf("%d\n",valorRetorno);
      
      return valorRetorno;
    }
  }
  printf("\n************Variable No Declarada*****************\n");
  return 0;
}
