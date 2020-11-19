# Resolución

## Nivel léxico del lenguaje.

Las cateregorias léxicas o tokens que se hayan en el trabajo se puede categorizar en 4:

- Números.
- Variables.
- Suma.
- Multiplicacion
- Parentesis Izquierdo
- Parentesis Derecho


A diferencia de la anterior resolución, el scanner se realiza con flex. A partir de ciertas expresiones regurales se realiza una accion, la cual retornara el token encontrado. Para  mantener la interfaz se mantuvo la funcion `GetNextToken`  que en vez de invocar a `scanner()` invoca al analizador lexico `yylex()`. En cada acción se realiza un `strcpy` del valor de la variable `yytext` a `val` para mantener la firma de la anterior resolución, por lo que para el parser no se modificará. 


## Nivel sintáctico del lenguaje.

Para el nivel sintactico se generó el siguiente autómata:
```
<programa> ::= <listaSentencia> FDT
<listaSentencia>::=  <sentencia> | <listaSentencia> <sentencia>
<sentencia>::= <identificador> = <numero> | Token_Calculo <expresion>
<expresion>::=  <termino> | <expresion> + <termino>
<termino> ::= <factor> |  <factor> * <termino>
<factor> ::= <numero> | <identificador> | ( <expresion> )
```

A diferencias de las otras versiones, el parser se realizó con bison, la cual declarando las gramaticas en bnf. Dado que bison utiliza yylex() para comunicarse con el bison, se realizó una funcion la cual se comunica con la funcion GetNextToken definida de forma manual, que en el scanner hará uso de yylex para consumir token y mantener la interfaz definida en las anteriores alternativas.

Por otra parte en el `parser.y` se definen los nuevos token, los cuales se define el tipo de valor que debera retornar el scanner. Para el caso de las variables (identificadores) será una cadena de caracteres, mientras que para el tipo token numero será un `int`. Para el resto de los token se definió como cadena de caracteres, de todas formas ya que la calculadora no hace uso de estos valores.


Nota: Para resolver la asignacion de valores a variables se utiliza una tabla de simbolos, que en el caso de que ya este definida la variable se pisará el valor, y en el caso de que la variable no este declarada se informará en stdout y el valor que se retorna es 0 cuando se solicite el valor de la variable