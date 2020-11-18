#pragma once

typedef enum{
    Token_MULTIPLICADOR,
    Token_SUMA,
    Token_VARIABLE,
    Token_NUMERO,
    Token_LBRACKET,
    Token_RBRACKET,
    Token_ERRORLEXICO,
    Token_ASIGNACION,
    Token_CALCULO,
    FDT
} TipoToken;


#define MAXVAL 100
extern char lexema[MAXVAL];