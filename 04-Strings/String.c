/* Qué: StringsTest.c
* Biblioteca creada de strings
* Quién: Matias Nigliazzo
* Cuando: 20200621
*/

#include"String.h"
#include<stdlib.h>



int GetLongitud(char* A){
    int i;
    char* C=A;

    if (*C!='\0'){
        C++;
        return (1+GetLongitud(C));
    }
    else{
     return 0;
    }
}


int IsVacia(char* A){
    return *A=='\0';
}


char* Potenciar(char* A,int n){
    int i;
    int j;
    int a=0;
    int largoPotenciado =GetLongitud(A)*n+1;
    char * copiaA= malloc(GetLongitud(A));
    copiaA=A;

    char* B= malloc(largoPotenciado);
    for (i=0;i<n;i++){
        for (j=a;*copiaA!='\0';j++){
            B[j]=*copiaA;
            copiaA++;
        }
        copiaA=A;
        a=j;
    }
    B[a]='\0';
    return B;
}


char* Concatenar (char*A,char*B){
    int largoA=GetLongitud(A);
    int largoB=GetLongitud(B);
    int largoC=largoA+GetLongitud(B)+1;
    char* C= malloc(largoC);
  
    int i;
    for(i=0;i<largoA;i++){
        C[i]=*A;
        A++;
    }
    for(i=largoA;i<largoC;i++){
        C[i]=*B;
        B++;
    }
    C[i]='\0';
    return C;

}