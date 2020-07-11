/* Qué: wl-1-enum-switch.c
* Maquina de Estado - Palabras en Lineas - enum switch
* Quién: Matias Nigliazzo
* Cuando: 20200713
*/
#include <stdio.h>
#include <assert.h>

typedef enum  {IN=1,OUT=0} State;

int main(void){
    int c,nl,nw,nc;
    State state;
    state=OUT;
    nl=nw=nc=0;

    while ((c=getchar())!=EOF){
        ++nc;
        switch (c){
            case '\n':
                ++nl;
                state=OUT;
            break;
            case ' ':
                state=OUT;
            break;
            case '\t':
                state=OUT;
            break;
            default:
                if (state==OUT){
                    ++nw;
                    state=IN;
                }  
            break;
        }       
    }
   printf("Line: %d Word: %d Characters: %d\n",nl,nw,nc);
}