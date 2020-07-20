/* Qué: wl-1-enum-switch.c
* Maquina de Estado - Palabras en Lineas - enum switch
* Quién: Matias Nigliazzo
* Cuando: 20200713
*/
#include <stdio.h>

int main(void)
{
  FILE *archivoSalida;
  int tamanio=0;
  int incremento=0;
  archivoSalida = fopen("entrada_wl.txt", "w+");
  printf("Ingrese cantidad de Kbytes para generar un txt:");
  scanf( "%d",&tamanio);
  while(incremento<tamanio)
  {
  fputs("PRUEBA Archivo\t\nOtra linea",archivoSalida);
  incremento=ftell(archivoSalida)/1024;
  }
}