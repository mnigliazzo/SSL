/* Qué: wl-3-rec.c
* Maquina de Estado - Palabras en Lineas - Recursiva
* Quién: Matias Nigliazzo
* Cuando: 20200720
*/
#include <stdio.h>

void Funcion_IN(void);
void Funcion_OUT(void);

int main()
{
  Funcion_OUT();
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