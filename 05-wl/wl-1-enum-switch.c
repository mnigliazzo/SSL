/* Qué: wl-1-enum-switch.c
* Maquina de Estado - Palabras en Lineas - enum switch
* Quién: Matias Nigliazzo
* Cuando: 20200713
*/
#include <stdio.h>
#include <time.h>

typedef enum
{
  IN,
  OUT
} State;

int main(void)
{
  clock_t start=0, end=0;
  double cpu_time_used;
  start = clock();
  int c;
  State state = OUT;
  FILE *archivoSalida, *archivoEntrada;
  archivoSalida = fopen("salida_wl_1_enum_switch.txt", "w+");
  archivoEntrada = fopen("entrada_wl.txt", "r");
  while ((c = fgetc(archivoEntrada)) != EOF)
  {
    switch (state)
    {
    case OUT:
      switch (c)
      {
      case ' ':
      case '\t':
      case '\n':
        break;
      default:
        state = IN;
        putc(c, archivoSalida);
        break;
      }
      break;
    case IN:
      switch (c)
      {
      case ' ':
      case '\t':
      case '\n':
        putc('\n', archivoSalida);
        state = OUT;
        break;
      default:
        
        putc(c, archivoSalida);
        break;
      }
    }
  }
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("En wl-1-enum-switch.c demoro: %f\n",cpu_time_used);
}