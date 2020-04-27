# Resolución Trabajo #2

### HelloWorld en C

    #include <stdio.h>
    int main() {
    printf("Hello, World!\n");
    }

### HelloWorld en C++

    #include <iostream>
    int main() {
    std::cout << "Hello, World!\n";
    }

## Comparativas entre las distintas variantes de HelloWorld

| Nivel | C | C++ |
| - | - | - |
| Léxico | `stdio.h` -> libreria estandar de entrada/salida<br>`printf()`</br> | `iostream` -> libreria estandar de entrada/salida<br>`<<`<br>`std::cout`</br> |
| Sintáctico | Igual | Igual |
| Semántico | `printf("Hello, World!\n");` <br>printf es una funcion a la cual se le pasa un parámetro y se encarga de que se visualice por pantalla el texto ingresado</br>| `std::cout << "Hello, World!\n";` <br>El operador `<<` es un operador de insersión, el cual inserta en este caso en el namespace estandar dedicado para la visualizacion en pantalla </br> |
