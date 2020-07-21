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
  int c;
  State state = OUT;
  while ((c = getchar()) != EOF)
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
        putchar(c);
        break;
      }
      break;
    case IN:
      switch (c)
      {
      case ' ':
      case '\t':
      case '\n':
        putchar('\n');
        state = OUT;
        break;
      default:
        
        putchar(c);
        break;
      }
    }
  }
}