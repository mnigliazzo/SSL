## GetLongitud

* Funcion: Obtiene el largo de una Cadena de Caracteres 
* Entrada: Cadena de caracteres
* Salida: Entero
  
$GetLongitud:\Sigma^{*} \rightarrow N_o \cup 0 /GetLongitud(A) =\left\{ \begin{array}{ll} 0 & A =\epsilon \\ 1+GetLongitud(A) & A \neq \epsilon \end{array}\right.$

## IsVacía

* Funcion: Indica si la Cadena de Caracteres es vacia 
* Entrada: Cadena de caracteres
* Salida: Entero. 1 si es vacio, 0 si tiene datos

$IsVacia:\Sigma^{*} \rightarrow N_o \cup 0 /IsVacia(A) =\left\{ \begin{array}{ll} 1 & A =\epsilon \\ 0& A \neq \epsilon \end{array}\right.$

## Potenciar

* Funcion: Obtiene una Cadena de Caracteres potenciada n veces
* Entrada: Cadena de caracteres, entero (la potencia)
* Salida: Cadena de Caracteres

$Potenciar:\Sigma^{*} \times N_o \cup 0 \rightarrow Sigma^{*} /Potenciar(A,n) =\left\{ \begin{array}{ll} \epsilon & n =0 \\ (A)^n & n \neq 0 \end{array}\right.$

## Concatenar

* Funcion: Obtiene la concatenacion de dos Cadenas de Caracteres 
* Entrada: Cadena de caracteres, Cadena de caracteres
* Salida: Cadena de caracteres

$Concatenar:\Sigma^{*} \times \Sigma^{*} \rightarrow Sigma^{*} /Concatenar(A,B) = A . B$
