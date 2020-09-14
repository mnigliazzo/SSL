/* Qué: Scanner.h
* Prototipos para el scanner
* Quién: Matias Nigliazzo
* Cuando: 20200913
*/


typedef enum{
    Token_OPERADOR,
    Token_VARIABLE,
    Token_NUMERO,
    Token_INVALIDO,
    FDT
} Token;

typedef enum
{
  INICIAL,
  OPERADOR,
  VARIABLE,
  NUMERO,
  RECHAZO
} StateScanner;

int esOperador(const char);
int esVariable(const char);
int esNumero(const char);
void errorLexico();
Token GetNextToken(); // Devuelve el tipo de token que encuentra

