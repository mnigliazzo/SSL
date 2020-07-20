/* Qué: wl-3-rec.c
* Maquina de Estado - Palabras en Lineas - Recursiva
* Quién: Matias Nigliazzo
* Cuando: 20200720
*/
#include <stdio.h>
#include <time.h>

void Funcion_IN(FILE *entrada, FILE *salida);
void Funcion_OUT(FILE *entrada, FILE *salida);

int main()
{
  clock_t start=0, end=0;
  double cpu_time_used;
  start = clock();
  FILE *archivoSalida, *archivoEntrada;
  archivoSalida = fopen("salida_wl_3_rec.txt", "w+");
  archivoEntrada = fopen("entrada_wl.txt", "r");
  Funcion_OUT(archivoEntrada, archivoSalida);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("En wl-3-rec.c demoro: %f\n",cpu_time_used);
}



void Funcion_OUT(FILE *entrada, FILE *salida)
{
int c;
  switch (c= fgetc(entrada))
  {
  case EOF:
    break;
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
    break;
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