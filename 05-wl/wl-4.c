/* Qué: wl-4.c
* Maquina de Estado - Palabras en Lineas - x
* Quién: Matias Nigliazzo
* Cuando: 20200720
*/
#include <stdio.h>

void Funcion_X(void);
void Funcion_PrintChar(int c);
void Funcion_PrintBreak(int c);
void Funcion_Null(int c);

typedef enum
{
  IN,
  OUT
} State;


int main()
{
  Funcion_X();
}

void Funcion_Null(int c)
{
}

void Funcion_PrintChar(int c)
{
  putchar(c);
}

void Funcion_PrintBreak(int c)
{

  putchar('\n');
}
void Funcion_X(void)
{
  int c;
  int stateActual=OUT,stateSiguiente;
  void (*fsm [2] [2]) (int);// Inicial Final Transision
  fsm[OUT][OUT]=&Funcion_Null;
  fsm[OUT][IN]=&Funcion_PrintChar;
  fsm[IN][OUT]=&Funcion_PrintBreak;
  fsm[IN][IN]=&Funcion_PrintChar;

  while ((c = getchar()) != EOF)
  {
    switch (c)
    {
    case ' ':
    case '\t':
    case '\n':
      stateSiguiente=OUT;
      break;
    default:
      stateSiguiente = IN;
    }
    fsm[stateActual][stateSiguiente](c);
    stateActual=stateSiguiente;
  }
}
