# Trabajo #6

## Autor de la resolución

* **Usuario GitHub:** mnigliazzo
* **Legajo:** 146.806.6
* **Apellido:** Nigliazzo
* **Nombre:** Matias Ezequiel

## Número y título del trabajo

* 14 - Calculadora Infija: Construcción Manual

## Enunciado

### Objetivos

* Experimentar el diseño de la especificación de lenguajes a nivel léxico y sintáctico.
* Experimentar la implementación manual del nivel léxico y sintáctico de lenguajes.

### Temas

* Especificación del nivel Léxico y Sintáctico.
* Implementación del nivel Léxico y Sintáctico.
* Implementación de Scanner
* Implementación de Parser

### Problema

Análisis de expresiones aritméticas infijas simples que incluya:

* Números naturales con representación literal en base 10.
* Identificadores de variables.
* Adición.
* Multiplicación.

Ejemplos de expresiones incorrectas:

```
A+2*3
2*A+3
A
2
```
Ejemplos de expresiones incorrectas:
```
+
42+
+A
```

### Solución

Especificar e implementar los niveles léxicos y sintácticos del lenguaje.

### Restricciones

* El scanner y el parser deben estar lógicamente separados.
* El parser se comunica con el scanner con la operación `GetNextToken`, el scanner toma los caracteres de `stdin` con getchar.

### Tareas

1. Diseñar el nivel léxico del lenguaje.
2. Diseñar el nivel sintáctico del lenguaje.
3. Implementar el scanner.
4. Implementar el parser.
5. Probar

### Productos

* `readme.md`
* `Calc.md`
* `Makefile`
* `Scanner.h`
* `Parser.h`
* `Parser.c`
* `Scanner.c`
* `Calc.c`

## Hipótesis de trabajo que surgen luego de leer el enunciado



