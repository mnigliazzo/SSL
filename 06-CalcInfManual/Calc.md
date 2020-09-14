# Resolución

## Nivel léxico del lenguaje.

Las cateregorias léxicas o tokens que se hayan en el trabajo se puede categorizar en tres:

- Números.
- Variables.
- Operadores.

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
Para los Operadores, el lenguaje Regular que se debe detectar es:
```
<operadores> ::= * | +
```

## Nivel sintáctico del lenguaje.



```
<expresion>::= <termino> | <termino> <operacion> <termino>
<operacion> ::= <operadores>
<termino> ::= <variables> | <numero natural> 
```

Dado que existen dos estados iniciales validos (una letra o un digito) se creo un estado inicial el cual representa el estado inicial el cual depende el ingreso del token transisionará al estado correspondiente
