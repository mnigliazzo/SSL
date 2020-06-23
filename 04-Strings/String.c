/* Qué: StringsTest.c
* Biblioteca creada de strings
* Quién: Matias Nigliazzo
* Cuando: 20200621
*/

#include"String.h"
#include<stdlib.h>



int GetLongitud(const char* A){
    int i;

    if (*A!='\0'){
           return (1+GetLongitud(A+1));
    }
    else{
     return 0;
    }
}


int IsVacia(const char* A){
    return *A=='\0';
}


const char* Potenciar(const char* A,int n){
    int i=0;
    int j=0;
    int a=0;
    int k=0;
    int largoPotenciado =(GetLongitud(A)*n)+1;
    char* B= malloc(largoPotenciado);

    if (n!=0){ 
        for (i=0;i<n;i++){
            for (j=0;j<GetLongitud(A);j++){
                B[k]=A[j];
                k++;
            }          
        }
    }
    B[largoPotenciado-1]='\0';
    return B;
}


const char* Concatenar (const char*A,const char*B){
    int largoA=GetLongitud(A);
    int largoB=GetLongitud(B);
    int largoC=largoA+largoB+1;
    int j=0;
    char* C= malloc(largoC);
    int i;
    for(i=0;i<largoA;i++){
        C[i]=A[i];
    }
    for(i=largoA;i<largoC;i++){
        C[i]=B[j++];
    }
    C[largoC-1]='\0';
    return C;

}