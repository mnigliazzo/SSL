# C vs C ++

## C

a. ¿El tipo es parte del lenguaje en algún nivel? **No**, se resuelve como un array de caracteres y para finalizar se utiliza el valor *\0* la ultima posición del array

b. ¿El tipo es parte de la biblioteca? **No** existe el tipo en C pero existe funciones en la biblioteca para tratar cadenas

c. ¿Qué alfabeto usa? UTF-8 (Unicode)

d. ¿Cómo se resuelve la alocación de memoria? Puede ser a traves de un array de tamaño fijo (estatico), o por medio de un puntero de forma dinamica con la funcion `malloc` . Y se alamacenan en el Stack

e. ¿El tipo tiene mutabilidad o es inmutable? Tiene Mutabilidad

f. ¿El tipo es un first class citizen? **No**

g. ¿Cuál es la mecánica para ese tipo cuando se los pasa como argumentos? Para enviar como argumento se envia el puntero. Indicando la primer posición de la cadena

h. ¿Y cuando son retornados por una función? También se devuelve un puntero 

## C ++

a. ¿El tipo es parte del lenguaje en algún nivel? **Si**

b. ¿El tipo es parte de la biblioteca?  **Si**. Existe una biblioteca nativa que tiene las funciones necesarias para el manejo de string

c. ¿Qué alfabeto usa? UTF-8 (Unicode)

d. ¿Cómo se resuelve la alocación de memoria? Se resuelve de Forma Dinamica. Y se almacena en el Heap

e. ¿El tipo tiene mutabilidad o es inmutable? Es Mutable

f. ¿El tipo es un first class citizen? **Si**

g. ¿Cuál es la mecánica para ese tipo cuando se los pasa como argumentos? un ejemplo de un header es `void funcionejemplo (string)`

h. ¿Y cuando son retornados por una función? un ejemplo de un header es `string funcionejemplo2 (string)`