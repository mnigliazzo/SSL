/* Qué: wl-3-rec.c
* Maquina de Estado - Palabras en Lineas - Goto
* Quién: Matias Nigliazzo
* Cuando: 20200720
*/
#include <stdio.h>
#include <assert.h>

void Funcion_IN(FILE *entrada, FILE *salida);
void Funcion_OUT(FILE *entrada, FILE *salida);

int main()
{
  FILE *archivoSalida, *archivoEntrada;
  archivoSalida = fopen("salida_wl_3_rec.txt", "w+");
  archivoEntrada = fopen("entrada_wl.txt", "r");
  Funcion_OUT(archivoEntrada, archivoSalida);
}



void Funcion_OUT(FILE *entrada, FILE *salida)
{
int c;
  switch (c= fgetc(entrada))
  {
  case EOF:
    return;
  case ' ':
  case '\t':
  case '\n':
     Funcion_OUT(entrada, salida);
      break;
  default:
    putc(c, salida);
    Funcion_IN(entrada, salida);
  }
}

void Funcion_IN(FILE *entrada, FILE *salida)
{
  int c;
  switch (c= fgetc(entrada))
  {
  case EOF:
    return;
  case ' ':
  case '\t':
  case '\n':
    putc('\n', salida);
    Funcion_OUT(entrada, salida);
    break;
  default:
    putc(c, salida);
    Funcion_IN(entrada, salida);
  }
}