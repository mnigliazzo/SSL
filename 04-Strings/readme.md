# Trabajo #4

## Autor de la resolución

* **Usuario GitHub:** mnigliazzo
* **Legajo:** 146.806.6
* **Apellido:** Nigliazzo
* **Nombre:** Matias Ezequiel

## Número y título del trabajo

* 08 - Operaciones de Strings

## Enunciado

### Objetivos

1. Parte I — Análisis Comparativo del tipo String en Lenguajes de Programación:

    Realizar un análisis comparativo de dato String en el lenguaje C versus un lenguaje de programación a elección. El análisis debe contener, por lo menos, los siguientes ítems:
    
    a. ¿El tipo es parte del lenguaje en algún nivel?

    b. ¿El tipo es parte de la biblioteca?

    c. ¿Qué alfabeto usa?

    d. ¿Cómo se resuelve la alocación de memoria?

    e. ¿El tipo tiene mutabilidad o es inmutable?

    f. ¿El tipo es un first class citizen?

    g. ¿Cuál es la mecánica para ese tipo cuando se los pasa como argumentos?

    h. ¿Y cuando son retornados por una función?Las anteriores preguntas son disparadores para realizar una análisis profundo.

2. Parte II — Biblioteca para el Tipo String: Desarrollar una biblioteca con las siguientes operaciones de strings:

    a. GetLength ó GetLongitud

    b. IsEmpty ó IsVacía

    c. Power ó Potenciar

    d. Una operación a definir libremente.

Notar que en vez de la operación concatenar que propone [MUCH2012] se debe desarrollar Power ó Potenciar que repite un string n veces. La parte pública de la biblioteca se desarrolla en el header "String.h", el cual no debe incluir <string.h>. El programa que prueba la biblioteca, por supuesto, incluye a "String.h", pero sí puede incluir <string.h> para facilitar las comparaciones.

### Temas

* Strings.
* Alocación.
* Tipos.

### Tareas

1. Parte I
   
   a. Escribir el AnálisisComparativo.md con la comparación de strings en C versus otro lenguaje de programación a elección.

2. Parte II
   
    a. Para cada operación, escribir en Strings.md la especificación matemática de la operación, con conjuntos de salida y de llegada, y con especificación de la operación.

    b. Escribir el Makefile.

    c. Por cada operación:
        
        i. Escribir las pruebas en StringsTest.c.
        
        ii. Escribir los prototipos en String.h.

        iii. Escribir en String.h comentarios con las precondiciones y poscondiciones de cada función, arriba de cada prototipo.
        
        iv. Escribir las implementaciones en Strings.c.

### Restricciones

* Las pruebas deben utilizar assert.
* Los proptotipos de utilizar const cuando corresponde.
* Por lo menos una operación debe implementarse con recursividad.
* Las implementaciones no deben utilizar funciones estándar, declaradas en <string.h>

### Productos

* `readme.md`
* `AnálisisComparativo.md`
* `String.md`
* `Makefile`
* `StringTest.c`
* `String.h`
* `String.c`

## Hipótesis de trabajo que surgen luego de leer el enunciado

Conocer como maneja el lenguaje `C` los strings