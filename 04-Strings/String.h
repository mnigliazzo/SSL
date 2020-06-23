/* Qué: StringsTest.c
* Prototipo funciones
* Quién: Matias Nigliazzo
* Cuando: 20200621
*/

#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

//Obtiene la longitud de una cadena de caracteres, en el caso de que sea vacia devuelve 0
int GetLongitud(const char* A);

//devuelve 1 si la cadena de caracteres esta vacia, de lo contrario devuelve 0
int IsVacia(const char* A);

//Realiza la potencia de una cadena de caracteres, en el caso de que n sea 0, devuelve la cadena recibida
const char* Potenciar(const char* A,int n);

//Concatena dos cadenas de caracteres
const char* Concatenar (const char*A,const char*B);

#endif