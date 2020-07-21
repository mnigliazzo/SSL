/* Qué: wl-3-rec.c
* Maquina de Estado - Palabras en Lineas - Recursiva
* Quién: Matias Nigliazzo
* Cuando: 20200720
*/
#include <stdio.h>
#include <time.h>

void Funcion_IN(void);
void Funcion_OUT(void);

int main()
{
  clock_t start=0, end=0;
  double cpu_time_used;
  start = clock();
  FILE *archivoSalida, *archivoEntrada;
  Funcion_OUT();
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("En wl-3-rec.c demoro: %f\n",cpu_time_used);
}



void Funcion_OUT(void)
{
int c;
  switch (c= getchar())
  {
  case EOF:
    break;
  case ' ':
  case '\t':
  case '\n':
     Funcion_OUT();
      break;
  default:
    putchar(c);
    Funcion_IN();
  }
}

void Funcion_IN(void)
{
  int c;
  switch (c= getchar())
  {
  case EOF:
    break;
  case ' ':
  case '\t':
  case '\n':
    putchar('\n');
    Funcion_OUT();
    break;
  default:
    putchar(c);
    Funcion_IN();
  }
}