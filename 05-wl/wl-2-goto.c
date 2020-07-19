/* Qué: wl-2-goto.c
* Maquina de Estado - Palabras en Lineas - Goto
* Quién: Matias Nigliazzo
* Cuando: 20200713
*/
#include <stdio.h>
#include <assert.h>

typedef enum
{
  IN,
  OUT
} State;

int main()
{
  int c;
  State state = OUT;
  FILE *archivoSalida, *archivoEntrada;
  archivoSalida = fopen("salida_wl_2_goto.txt", "w+");
  archivoEntrada = fopen("entrada_wl.txt", "r");

OUT:
  if ((c = fgetc(archivoEntrada)) != EOF)
  {
    switch (c)
    {
    case ' ':
    case '\t':
    case '\n':
      if (state == OUT)
      {
        putc('\n', archivoSalida);
      }
    default:
      state = IN;
      goto IN;
    }
  }
  else
    return 0;

IN:
  switch (c)
  {
  case ' ':
  case '\t':
  case '\n':
    state = IN;
    goto OUT;
  default:
    if (state == IN)
    {
      putc(c, archivoSalida);
      state = OUT;
    }
    goto OUT;
  }
}