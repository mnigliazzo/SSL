/* Qué: wl-4.c
* Maquina de Estado - Palabras en Lineas - Goto
* Quién: Matias Nigliazzo
* Cuando: 20200720
*/
#include <stdio.h>
#include <assert.h>

void Funcion_X(FILE *entrada, FILE *salida);
void Funcion_PrintChar(int c,FILE *salida);
void Funcion_PrintBreak(int c, FILE *salida);
void Funcion_Null(int c,FILE *salida);

typedef enum
{
  IN=1,
  OUT=0
} State;


int main()
{
  FILE *archivoSalida, *archivoEntrada;
  archivoSalida = fopen("salida_wl_4.txt", "w+");
  archivoEntrada = fopen("entrada_wl.txt", "r");
  
  Funcion_X(archivoEntrada, archivoSalida);
}

void Funcion_Null(int c,FILE *salida)
{
}

void Funcion_PrintChar(int c,FILE *salida)
{
  putc(c, salida);
}

void Funcion_PrintBreak(int c, FILE *salida)
{

  putc('\n', salida);
}
void Funcion_X(FILE *entrada, FILE *salida)
{
  int c;
  int stateActual=OUT,stateSiguiente;
  void (*fsm [2] [2]) (int, FILE*);// Inicial Final Transisio
  fsm[OUT][OUT]=&Funcion_Null;
  fsm[OUT][IN]=&Funcion_PrintChar;
  fsm[IN][OUT]=&Funcion_PrintBreak;
  fsm[IN][IN]=&Funcion_PrintChar;

  while ((c = fgetc(entrada)) != EOF)
  {
    switch (c)
    {
    case ' ':
    case '\t':
    case '\n':
      stateSiguiente=OUT;
      break;
    default:
      stateSiguiente = IN;
    }
    fsm[stateActual][stateSiguiente](c,salida);
    stateActual=stateSiguiente;
  }
}
