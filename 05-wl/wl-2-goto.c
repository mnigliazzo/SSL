/* Qué: wl-2-goto.c
* Maquina de Estado - Palabras en Lineas - Goto
* Quién: Matias Nigliazzo
* Cuando: 20200713
*/
#include <stdio.h>
#include <time.h>

int main()
{
  clock_t start=0, end=0;
  double cpu_time_used;
  start = clock();
  int c;
  FILE *archivoSalida, *archivoEntrada;
  archivoSalida = fopen("salida_wl_2_goto.txt", "w+");
  archivoEntrada = fopen("entrada_wl.txt", "r");

OUT:
  switch (c = fgetc(archivoEntrada))
  {
  case EOF:
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("En wl-2-goto.c demoro: %d\n",cpu_time_used);
    return 0;
  case ' ':
  case '\t':
  case '\n':
    goto OUT;
    break;
  default:
    putc(c, archivoSalida);
    goto IN;
  }

IN:
  switch (c = fgetc(archivoEntrada))
  {
  case EOF:
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("En wl-2-goto.c demoro: %f\n",cpu_time_used);
    return 0;
  case ' ':
  case '\t':
  case '\n':
    putc('\n', archivoSalida);
    goto OUT;
  default:
    putc(c, archivoSalida);
    goto IN;
  }

}