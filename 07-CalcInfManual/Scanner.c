/* Qué: Scanner.c
* Biblioteca creada para scanner (Analizador Léxico)
* Quién: Matias Nigliazzo
* Cuando: 20200913
*/

#include "Scanner.h"

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
static int sp = 0; /* next free stack position */
void errorLexico();
bool isPlus(const int);
bool isMultiplication(const int);
bool isFDT(const int);
bool isRBracket(const int);
bool isLBracket(const int);
void leerTokenVariable();
void leerTokenDigito();
void finToken(void);
// char* obtenerToken();
void escribirToken(int);
// void clean();
Token scanner();
int flagToken = 0;
char val[MAXVAL];
Token tokenActual;
Token GetNextToken()
{

  if (!flagToken) //si es 0
  {

    tokenActual = scanner();
    if (tokenActual == Token_ERRORLEXICO)
      errorLexico();
    flagToken = 1;
  }
  return tokenActual;
}
Token scanner()
{

  int c;
  c = getchar();
  if (isFDT(c))
  {
    return FDT;
  }
  else if (isalpha(c))
  {
    escribirToken(c);
    leerTokenVariable();
    return Token_VARIABLE;
  }
  else if (isdigit(c))
  {
    escribirToken(c);
    leerTokenDigito();
    return Token_NUMERO;
  }
  else if (isMultiplication(c))
  {
    escribirToken(c);
    finToken();
    return Token_MULTIPLICADOR;
  }
  else if (isPlus(c))
  {
    escribirToken(c);
    finToken();
    return Token_SUMA;
  }
  else if (isLBracket(c))
  {
    escribirToken(c);
    finToken();
    return Token_LBRACKET;
  }
  else if (isRBracket(c))
  {
    escribirToken(c);
    finToken();
    return Token_RBRACKET;
  }
  else if (isspace(c))
  {
    GetNextToken();
  }
  else
  {
    errorLexico();
    return Token_ERRORLEXICO;
  }
}

bool isMultiplication(const int c)
{
  if (c == '*')
    return true;
  return false;
}

bool isPlus(const int c)
{
  if (c == '+')
    return true;
  return false;
}

bool isLBracket(const int c)
{
  if (c == '(')
    return true;
  return false;
}
bool isRBracket(const int c)
{
  if (c == ')')
    return true;
  return false;
}

bool isFDT(const int c)
{
  if (c == EOF)
    return true;
  return false;
}
void leerTokenVariable()
{
  int c;
  c = getchar();

  if (isFDT(c))
  {
    finToken();
    ungetc(c, stdin);
    return;
  }
  else if (isalpha(c))
  {
    escribirToken(c);
    leerTokenVariable();
  }
  else if (isdigit(c))
  {
    escribirToken(c);
    leerTokenVariable();
  }
  else
  {
    finToken();
    ungetc(c, stdin);
    return;
  }
}

void leerTokenDigito()
{
  int c;
  c = getchar();
  if (isFDT(c))
  {
    finToken();
    ungetc(c, stdin);
    return;
  }
  else if (isdigit(c))
  {
    escribirToken(c);
    leerTokenDigito();
  }
  else
  {
    finToken();
    ungetc(c, stdin);
    return;
  }
}

void escribirToken(int c)
{

  if (sp < MAXVAL)
    val[sp++] = c;
  return;
}

char *obtenerToken()
{

  char *r;
  r = val;

  return r;
}

void finToken(void)
{
  escribirToken('\0');
}

void errorLexico()
{
  printf("Error Lexico\n");
}

// void clean(void)
// {
//   sp=0;
//   val[sp]='\0';
// }
