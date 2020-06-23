/* Qué: StringsTest.c
* Prueba Biblioteca String
* Quién: Matias Nigliazzo
* Cuando: 20200621
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "String.h"


int main(void)
{
    char* stringVacio="\0";
    char* stringHello="Hello World";
    char* stringPrueba=", Hola Mundo";
    int cantidadPotenciado;
    int cantidadleft;


    cantidadPotenciado=2;
    cantidadleft=5;

    printf("Revision String Vacio!\n");
    assert(IsVacia(stringVacio)==1);
    printf("Revision String No Vacio!\n");
    assert(IsVacia(stringHello)!=1);


    printf ("La longitud de \"%s\" es %d\n",stringHello,GetLongitud(stringHello));
    assert(GetLongitud(stringHello)==11);
    printf ("La longitud de \"%s\" es %d\n",stringVacio,GetLongitud(stringVacio));
    assert(GetLongitud(stringVacio)==0);


    printf ("El potenciado de \"%s\" de %d veces es \"%s\" y mide %d\n",stringHello,cantidadPotenciado,Potenciar(stringHello,cantidadPotenciado),GetLongitud(Potenciar(stringHello,cantidadPotenciado)));
    assert(GetLongitud(Potenciar(stringHello,cantidadPotenciado))==(GetLongitud(stringHello)*cantidadPotenciado));


     printf ("La funcion concatenar entre \"%s\" y \"%s\"  \"%s\"\n",stringHello,stringPrueba,Concatenar(stringHello,stringPrueba));
     assert(GetLongitud(Concatenar(stringHello,stringPrueba))==(GetLongitud(stringHello)+GetLongitud(stringPrueba)));

}





