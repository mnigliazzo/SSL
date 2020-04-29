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
| Léxico | Difieren Tokens<br>`stdio.h` -> librería estandar de entrada/salida<br>`printf()`</br> | Difieren Tokens<br>`iostream` -> librería estandar de entrada/salida<br>`<<`<br>`std::cout`</br> |
| Sintáctico | A grandes rasgos la estructura idénticas <br>Las sentencias de expresión son sufijas</br> | A grandes rasgos la estructura son idénticas <br>Las sentencias de expresión son infijas</br> |
| Semántico | `printf("Hello, World!\n");` <br>printf es una función a la cual se le pasa un parámetro y se encarga de que se visualice por pantalla el texto ingresado</br>| `std::cout << "Hello, World!\n";` <br>El operador `<<` es un operador de inserción, el cual inserta en este caso en el namespace estandar dedicado para la visualización en pantalla </br> |
