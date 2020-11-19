%{
  #include <stdio.h>
  #include <string.h>
  #include "Scanner.h"
  #include "Parser.h"
  #include "Token.h"
  #include "TablaSimbolos.h"


void yyerror(char const *s){printf ("Error en el Parser: %s\n", s);} // cuando yyparser detecta un error sintacto hace uso de yyerror, por lo cual es necesario declararla

static int yylex();
  


%}

%union { //declara los tipos de valores de los token para el analisis semantico
  int intVal;
  char strVal[100];
}

%token <strVal> Token_MULTIPLICADOR
%token <strVal> Token_SUMA
%token <strVal> Token_VARIABLE
%token <intVal> Token_NUMERO
%token <strVal> Token_LBRACKET
%token <strVal> Token_RBRACKET
%token <strVal> Token_ASIGNACION
%token <strVal> Token_ERRORLEXICO
%token <strVal> Token_CALCULO
%token <strVal> FDT 0 // es necesario darle el valor cero para indicar que es el token de EOF
%type <intVal> sentencia
%type <intVal> expresion
%type <intVal> termino
%type <intVal> factor
%type <intVal> listaSentencia
%type <intVal> programa

%%
programa: listaSentencia FDT;

listaSentencia: sentencia 
  | listaSentencia sentencia;

sentencia: Token_VARIABLE Token_ASIGNACION Token_NUMERO {agregarTablaSimbolos($1,$3); }
  | Token_CALCULO expresion {printf("El resultado es: %d\n", $2);};

expresion: termino {$$=$1;}
 | expresion Token_SUMA termino {$$=$1+$3;}
 ;

termino: factor {$$=$1;}
 | factor Token_MULTIPLICADOR termino {$$=$1*$3;}
 ;

factor: Token_VARIABLE {$$=buscarTablaSimbolos($1);}
 | Token_NUMERO {$$=$1;}
 | Token_LBRACKET expresion Token_RBRACKET {$$=$2;}
;



%%


static int yylex(void){   
    return GetNextToken();
}

void parser(){
  switch(yyparse()){
    case 0:
      return;
    case 1:
     printf("Error Sintactico \n");
     return;
    default:
      printf("Otro Error\n");
      return;
  }
}


