# Resolución Trabajo #3

## Autor de la resolución

* **Usuario GitHub:** mnigliazzo
* **Legajo:** 146.806.6
* **Apellido:** Nigliazzo
* **Nombre:** Matias Ezequiel

## Número y título del trabajo

* 03 - Fases de la Traducción y Errores

## Enunciado

### Objetivos

* Identificar las fases de traducción y errores.

### Temas

* Fases de traducción.
* Preprocesamiento.
* Compilación.
* Ensamblado.
* Vinculación (Link).
* Errores en cada fase

### Tareas

1. Investigar las funcionalidades y opciones que su compilador presenta para limitar el inicio y fin de las fases de traducción.
2. Para la siguiente secuencia de pasos:
    a. Transcribir en readme.md cada comando ejecutado y
    b. Describir en readme.md el resultado u error obtenidos para cada paso

### Restricciones

* El programa ejemplo debe enviar por stdout la frase La respuesta es 42, el valor 42 debe surgir de una variable.

### Productos

* `.gitignore`
* `readme.md`
* `hello2.c`
* `hello3.c`
* `hello4.c`
* `hello5.c`
* `hello6.c` 
* `hello7.c`

## Hipótesis de trabajo que surgen luego de leer el enunciado

Generar los archivos del preprocesador y ver como se modifican con respecto a las modificaciones que se realizan sobre el programa

## Resolución

1. Escribir hello2.c, que es una variante de hello.c:

        #include <stdio.h>

        int/*medio*/main(void){
        int i=42;
        prontf("La respuesta es %d\n");

2. Preprocesar hello2.c, no compilar, y generar hello2.i. Analizar su contenido.

    Sentencia: `gcc hello2.c -std=c18 -E -o hello2.i`

    Genera un nuevo archivo con el programa preprocesado, reemplazando el  `#include <stdio.h>` por lo que se encuentra en el archivo stdio.h. También reemplaza los comentarios por un espacio.

3. Escribir hello3.c, una nueva variante:
   
        int printf(const char *s, ...);

        int main(void){
        int i=42;
        prontf("La respuesta es %d\n");

4. Investigar la semántica de la primera línea.

    Declara el prototipo de la función `printf`. Indicando los parámetros que recibirá

5. Preprocesar hello3.c, no compilar, y generar hello3.i. Buscar diferencias entre hello3.c y hello3.i

    Sentencia: `gcc hello3.c -std=c18 -E -o hello3.i`

    Lo único que difiere es que agrega etiquetas del programa (no agrega ninguna biblioteca)

6. Compilar el resultado y generar hello3.s, no ensamblar

    Sentencia: 

            $ gcc hello3.i -std=c18 -S -o hello3.s
            hello3.c: In function 'main':
            hello3.c:9:2: warning: implicit declaration of function 'prontf'; did you mean 'printf'? [-Wimplicit-function-declaration]
                9 |  prontf("La respuesta es %d\n");
                  |  ^~~~~~
                  |  printf
            hello3.c:9:2: error: expected declaration or statement at end of input

    Al compilar, detecta una advertencia de sintaxis `prontf` sugiriendo la modificación a `printf`. Además existe un error, la cual no cierra la llave del main. por lo que no genera hello3.s

7. Corregir en el nuevo archivo hello4.c y empezar de nuevo, generar hello4.s, no ensamblar.

    Sentencia: 

            $ gcc hello4.c -std=c18 -E -o hello4.i
            $ gcc hello4.i -std=c18 -S -o hello4.s
            hello4.c: In function 'main':
            hello4.c:9:2: warning: implicit declaration of function 'prontf'; did you mean 'printf'? [-Wimplicit-function-declaration]
                9 |  prontf("La respuesta es %d\n");
                  |  ^~~~~~
                  |  printf
      
    Se corrigió solo el error de la llave. Al compilar detecta una advertencia para `prontf`.

8. Investigar hello4.s

    Genera el Assembler del programa hello4.c 

9.  Ensamblar hello4.s en hello4.o, no vincular

    Sentencia: `as hello4.s -o hello4.o`
    
    Genera el Código Maquina del programa hello4.c

10. Vincular hello4.o con la biblioteca estándar y generar el ejecutable.

    Sentencia: 

            $ gcc hello4.o -L/c:/MinGW/include/stdio.h -o hello4.exe
            c:/mingw/bin/../lib/gcc/mingw32/9.2.0/../../../../mingw32/bin/ld.exe: hello4.o:hello4.c:(.text+0x1e): undefined reference to `prontf'
            collect2.exe: error: ld returned 1 exit status

    Se vincula el programa en lenguaje maquina con la biblioteca stdio que tiene definida la función printf. Cuando se genera el ejecutable, falla ya que no la advertencia que antes indicaba de `prontf` no puede referenciarla con ninguna función.

11. Corregir en hello5.c y generar el ejecutable.

    Sentencias: 

            $ gcc hello5.c -std=c18 -E -o hello5.i
            $ gcc hello5.i -std=c18 -S -o hello5.s
            $ as hello5.s -o hello5.o
            $ gcc hello5.o -L/c:/MinGW/include/stdio.h -o hello5.exe
          
    Sentencia que genera el ejecutable directamente: `gcc hello5.c -std=c18 -o hello5.exe`

12. Ejecutar y analizar el resultado.
    
            $ ./hello5.exe
            La respuesta es 4200688

    La corrección que se hizo fue `prontf` a `printf`, genera el Ejecutable sin errores ni advertencias. Al momento de visualizar el resultado por consola se visualiza un numero incorrecto porque no se pasó la variable i a printf. Este número corresponde al valor de inicio del stack según lo que se observa en hello5.s

13. Corregir en hello6.c y empezar de nuevo.

    Sentencias: 

            $ gcc hello6.c -std=c18 -E -o hello6.i
            $ gcc hello6.i -std=c18 -S -o hello6.s
            $ as hello6.s -o hello6.o
            $ gcc hello6.o -L/c:/MinGW/include/stdio.h -o hello6.exe
            $ ./hello6.exe
            La respuesta es 42
    
    Sentencia que genera el ejecutable directamente: `gcc hello6.c -std=c18 -o hello6.exe`

    Al generar el ejecutable no figura ningún error ni advertencia, el programa imprime el valor 42 ya que se lo pasa como argumento en el printf

14. Escribir hello7.c, una nueva variante:

    int main(void){
    int i=42;
    printf("La respuesta es %d\n", i);
    }

15. Explicar porqué funciona.

      Sentencias: 

            $ gcc hello7.c -std=c18 -E -o hello7.i
            $ gcc hello7.i -std=c18 -S -o hello7.s
            hello7.c: In function 'main':
            hello7.c:7:2: warning: implicit declaration of function 'printf' [-Wimplicit-function-declaration]
                7 |  printf("La respuesta es %d\n", i);
                  |  ^~~~~~
            hello7.c:7:2: warning: incompatible implicit declaration of built-in function 'printf'
            hello7.c:1:1: note: include '<stdio.h>' or provide a declaration of 'printf'
              +++ |+#include <stdio.h>
                1 | /* hello7.c
            $ as hello7.s -o hello7.o
            $ gcc hello7.o -L/c:/MinGW/include/stdio.h -o hello7.exe
            $ ./hello7.exe
            La respuesta es 42
    
    Sentencia que genera el ejecutable directamente: `gcc hello7.c -std=c18 -o hello7.exe`
    
    El programa funciona ya que el compilador cuando realiza la vinculación, vincula siempre con las biblioteca estándar, identificando así la función printf, por más que indique una advertencia. En la fase de compilación genera el warning de que no reconoce la función printf.
