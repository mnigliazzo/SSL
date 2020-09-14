/* Qué: Scanner.c
* Biblioteca creada para scanner (Analizador Léxico)
* Quién: Matias Nigliazzo
* Cuando: 20200913
*/

#include "Scanner.h"


Token GetNextToken()
{
  int c;
  StateScanner state = INICIAL;
  StateScanner StateAnterior=state;
  while ((c = getchar()) != EOF)
  {  
    if (esOperador(c))
    {
      state=OPERADOR;
    }
    else if (esNumero(c))
    {
      state=NUMERO;
    }
    else if (esVariable(c))
    {
      state=VARIABLE;
    }
    else
    {
      state=RECHAZO;
    }
    switch (state)
    {    
      case OPERADOR:
          return Token_OPERADOR;
      case NUMERO:
          if (StateAnterior==state)
            StateAnterior=NUMERO;
          else{
            return Token_NUMERO;  
          }
          break;        
      case VARIABLE:
       if (StateAnterior==state){
          StateAnterior=VARIABLE;
        }
        else{
          return Token_VARIABLE;
       }
        break;
      case RECHAZO:
        errorLexico();
        return Token_INVALIDO;  
    }
  }
  return FDT;

}

int esNumero(const char c){
  switch (c){
    case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
      return 1;
      break;
    default:
      return 0;
      break;
  }
}

int esVariable(const char c){
  switch (c){
    case 'a':case 'b':case 'c':case 'd':case 'e':case 'f':case 'g':case 'h':case 'i':case 'j':case 'k':case 'l':case 'm':case 'n':case 'o':case 'p':case 'q':case 'r':case 's':case 't':case 'u':case 'v':case 'w':case 'x':case 'y':case 'z':
      return 1;
      break;
    default:
      return 0;
      break;
  }
}

int esOperador(const char c){
  switch (c){
    case '+':case '*':
      return 1;
      break;
    default:
      return 0;
      break;
  }
}

void errorLexico(){
  printf("Error Lexico\n");
}