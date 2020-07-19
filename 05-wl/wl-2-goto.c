/* Qué: wl-2-goto.c
* Maquina de Estado - Palabras en Lineas - Goto
* Quién: Matias Nigliazzo
* Cuando: 20200713
*/
#include <stdio.h>
#include <assert.h>

int main()
{
  int c;
  FILE *archivoSalida, *archivoEntrada;
  archivoSalida = fopen("salida_wl_2_goto.txt", "w+");
  archivoEntrada = fopen("entrada_wl.txt", "r");

OUT:
  switch (c = fgetc(archivoEntrada))
  {
  case EOF:
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