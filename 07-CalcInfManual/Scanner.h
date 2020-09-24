/* Qué: Scanner.h
* Prototipos para el scanner
* Quién: Matias Nigliazzo
* Cuando: 20200913
*/
#ifndef scanner_h_
#define scanner_h_





typedef enum{
    Token_MULTIPLICADOR,
    Token_SUMA,
    Token_VARIABLE,
    Token_NUMERO,
    Token_LBRACKET,
    Token_RBRACKET,
    Token_ERRORLEXICO,
    FDT
} Token;



extern int flagToken;
Token GetNextToken(); // Devuelve el tipo de token que encuentra
extern Token tokenActual;
#define MAXVAL 100
extern char val[MAXVAL]; /* value stack */



// void printToken(); 

#endif
