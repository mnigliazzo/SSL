/* Qué: wl-2-goto.c
* Maquina de Estado - Palabras en Lineas - Goto
* Quién: Matias Nigliazzo
* Cuando: 20200713
*/
#include <stdio.h>

int main()
{
  int c;
OUT:
  switch (c = getchar())
  {
  case EOF:
    return 0;
  case ' ':
  case '\t':
  case '\n':
    goto OUT;
    break;
  default:
    putchar(c);
    goto IN;
  }

IN:
  switch (c = getchar())
  {
  case EOF:
    return 0;
  case ' ':
  case '\t':
  case '\n':
    putchar('\n');
    goto OUT;
  default:
    putchar(c);
    goto IN;
  }

}