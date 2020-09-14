# Resolución

## Nivel léxico del lenguaje.

Las cateregorias léxicas o tokens que se hayan en el trabajo se puede categorizar en 4:

- Números.
- Variables.
- Suma.
- Multiplicacion

Para los Números, el lenguaje Regular que se debe detectar es:
```
<número natural> ::= <dígito> | <número natural> <dígito>
<dígito> ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
```
Para las Variables, el lenguaje Regular que se debe detectar es:
```
<variables> ::= <letra> | <variables> <letra>
<letra> ::= a | b | c | d | e | f | g | h | i | j | k | l | m | n | o | p | q | r | s | t | u | v | w | x | y | z
```
Para los Suma, el lenguaje Regular que se debe detectar es:
```
<Suma> ::= +
```
Para los Multiplicacion, el lenguaje Regular que se debe detectar es:
```
<Multiplicacion> ::= *
```
### Maquina de Estado
![NivelLexico](.\img\nivellexico.gv.svg)

Cuando se codifico se generaron dos estados:
1. FDT, el cual indica que llego al ultimo caracter de la cadena
2. RECHAZO, el cual se utiliza para completar la maquina de estado para que no haya huecos


## Nivel sintáctico del lenguaje.

Para el nivel sintactico se generó el siguiente autómata:
```
<expresion>::= <termino> | <termino> <operacion> <termino>
<operacion> ::= <Suma> |  <Multiplicacion>
<termino> ::= <variables> | <numero natural> 
```

Dado que existen dos estados iniciales validos (una letra o un digito) se creo un estado inicial el cual representa el estado por el que comienza el ingreso de los tokens.

Para el diagrama de la maquina de estado se agrupo la suma y la multiplicación para que sea mas visible, ya que los dos tokens se deben representar de la misma forma en el automata.


### Maquina de Estado
![NivelSintactico](.\img\nivelsintactico.gv.svg)
