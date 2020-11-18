
#define MAXVAL 100

#include "TablaSimbolos.h"
#include <string.h>
#include <stdio.h>

typedef struct {
    char variable[MAXVAL];
    int valor;
}Simbolos;

Simbolos TablaSimbolos[MAXVAL];
int id_TablaSimbolos=0;


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