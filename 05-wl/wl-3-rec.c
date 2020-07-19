/* Qué: wl-3-rec.c
* Maquina de Estado - Palabras en Lineas - Goto
* Quién: Matias Nigliazzo
* Cuando: 20200720
*/
#include <stdio.h>
#include <assert.h>

void Funcion_IN(FILE *entrada, FILE *salida);
void Funcion_OUT(FILE *entrada, FILE *salida);
typedef enum
{
  IN,
  OUT
} State;
State state = OUT;
int main()
{
  FILE *archivoSalida, *archivoEntrada;
  archivoSalida = fopen("salida_wl_3_rec.txt", "w+");
  archivoEntrada = fopen("entrada_wl.txt", "r");
  Funcion_OUT(archivoEntrada, archivoSalida);
}
int c;
void Funcion_IN(FILE *entrada, FILE *salida)
{
  switch (c)
  {
  case EOF:
    return;
  case ' ':
  case '\t':
  case '\n':
    return;//Funcion_OUT(entrada, salida);
  default:
    if (state == IN)
    {
      putc(c, salida);

      state = OUT;
    }
    Funcion_OUT(entrada, salida);
  }
}

void Funcion_OUT(FILE *entrada, FILE *salida)
{
 
  c = fgetc(entrada);
  switch (c)
  {
  case EOF:
    return;
  case ' ':
  case '\t':
  case '\n':
    if (state == OUT)
    {
      putc('\n', salida);
    }
  default:
    state = IN;
    Funcion_IN(entrada, salida);
    Funcion_OUT(entrada, salida);
  }
}