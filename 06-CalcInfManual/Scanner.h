/* Qué: Scanner.h
* Prototipos para el scanner
* Quién: Matias Nigliazzo
* Cuando: 20200913
*/
#include <stdbool.h>
#include  <ctype.h> 
typedef enum{
    Token_MULTIPLICADOR,
    Token_SUMA,
    Token_VARIABLE,
    Token_NUMERO,
    Token_INVALIDO,
    FDT
} Token;

void errorLexico();
Token GetNextToken(); // Devuelve el tipo de token que encuentra
bool isPlus(const int);
bool isMultiplication(const int);
bool isFDT (const int);
void leerTokenVariable();
void leerTokenDigito();