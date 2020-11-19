/* Qué: Scanner.h
* Prototipos para el scanner
* Quién: Matias Nigliazzo
* Cuando: 20200913
*/

typedef enum{
    Token_MULTIPLICADOR,
    Token_SUMA,
    Token_VARIABLE,
    Token_NUMERO,
    Token_INVALIDO,
    FDT
} Token;


Token GetNextToken(); // Devuelve el tipo de token que encuentra
