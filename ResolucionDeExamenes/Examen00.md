# Resolución del [Examen #0](https://josemariasola.github.io/ssl/midterms/2020/Exam%20%230.pdf)

## 1. Parte I

1. Las tareas que más representan a un Ingeniero en Sistemas de Información es realizar el Análisis, Diseño e Implementación de Sistemas de Información.

2. Información es el conjunto de datos que tiene un sentido, es decir provee conocimiento del sistema y permite la toma de decisiones.

3. Las asignaturas del área de programación son:
   * Matemática Discreta
   * Algoritmos y estructuras de Datos
   * Sintaxis y Semántica de los Lenguajes
   * Paradigmas de Programación
   * Gestión de Datos

4. Las asignaturas del área de Sistemas de Información son:
   * Sistemas y Organizaciones
   * Análisis de Sistemas
   * Diseño de Sistemas
   * Administración de Recursos
   * Proyecto Final

5. El paradigma de programación que se aplicó en el primer año de la carrera es el procedural.

6. La abstracción es representar una expresión en una forma descriptiva, permitiendo descomponer el problema a resolver.

## 2. Parte II

1. La diferencia entre conjunto y secuencia es que el primero identifica a una colección de objetos de una misma especie, mientras que una secuencia indica, también, una colección de objetos pero que sus elementos tienen una orden especifico.

2. El concepto de Secuencia Matemática es la relación que existe entre dos conjuntos; el dominio esta comprendido por los números naturales, mientras que la imagen puede ser de cualquier especie.

3. Se define como Función Matemática a la relación que existe entre dos conjuntos (Dominio e Imagen). Para cada elemento del Dominio corresponde un único elemento del conjunto Imagen (unicidad). Además todo elemento del Dominio debe relacionarse con un elemento de la Imagen (existencia).

4. Un grafo es un conjunto de puntos (vertices) los cuales se encuentran unidos por aristas, estas sirven para representar relaciones entre los vertices.

5. La partición de un conjunto representa una división de un conjunto en las cuales no existen elemento que queden aislados a la división y cada subconjunto formado no comparten elementos en común.

6. P(X)={Ø,{a},{b},{a,b}}

7. Se define a lenguaje formal a las palabras formadas por el alfabeto. Siendo el alfabeto, elementos como letras, símbolos o caracteres; las palabras, una secuencia de elementos del alfabeto. El lenguaje también se forma con gramáticas, las cuales indican un conjunto de reglas para que el lenguaje sea válido.

8. Un autómata finito es una maquina que reconoce lenguajes, la cual permite reconocer si una palabra pertenece al lenguaje o no.

## 3. Parte III

1. Un algoritmo es una secuencia de instrucciones la cual permite resolver un problema.

2. La programación estructurada es un paradigma de programación que esta orientado a la claridad y utilizan solamente estructuras lógicas de control (secuencia, selección e iteración).

3. Tres estructuras de control de flujo de ejecución pueden ser:
   * Secuencia
   * Selección
   * Iterativa

4. La diferencia entre argumento y parámetro es que el parámetro representa el valor que  espera procedimiento, mientras que el argumento es el valor que se le pasa al procedimiento al llamarse

5. Algunos ejemplos de las formas de transferencia de argumentos son:
   * Valor/copia: se le indica el contenido del argumento.
   * Referencia: se le indica una dirección de memoria donde se encuentra el dato

6. Un parámetro en entrada es aquel parámetro que espera que se le ingrese al procedimiento, mientras que el de salida es el que devuelve luego de la ejecución. Por otra parte los de entrada/salida, son los que el procedimiento recibe y por el mismo parámetro devuelve el resultado luego de la ejecución

7. Un tipo de dato abstracto es un modelo en el cual encapsula cierto tipo de dato (entero, flotante, etc.) y tiene una serie de operaciones que se encuentran definidas para ese modelo. Un ejemplo de un tipo de dato abstracto es una lista.

8. La diferencia entre colas y pilas es en como se agregan y quitan elementos de la estrutura de dato. En las pilas se usa LIFO (last in first out, lo ultimo en entrar es lo primero en salir) y en colas se usa FIFO (first in first out, lo primero en entrar es lo primero en salir)

9. Los archivos son un tipo de estructura de datos que persisten en memoria.

10. Algoritmo de calculo de promedio:

*Diagrama de Flujo:*

![Diagrama](./Diagrama.jpg)

*Codificación:*

    float promedio (int a[],int n)
    {
      int s=0;
      float r=0;
      for (int i=0;i<n;i++)
      {  
        s=s+a[n];
      }
      r=s/n;
      return r;
    }
  El algoritmo solo funciona con una cadena no vacias, en caso de que se envie una cadena vacia dará error.
