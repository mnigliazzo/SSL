/* Qué: wl-2-goto.c
* Maquina de Estado - Palabras en Lineas - Goto
* Quién: Matias Nigliazzo
* Cuando: 20200713
*/
#include <stdio.h>
#include <assert.h>

typedef enum  {IN=1,OUT=0} State;

int main(void){
    int c,nl,nw,nc;
    State state=OUT;
    nl=nw=nc=0;

  Loop:
    if ((c=getchar())!=EOF){
        ++nc;
        if (c==' '||c=='\n'||c=='\t')
          goto OUT;
        else 
          goto IN;       
      }
    printf("Line: %d Word: %d Characters: %d\n",nl,nw,nc);
      
  IN:
    if (state==OUT)
    {
      ++nw;
      state=IN;
    }
    
    goto Loop;    
  OUT: 
    state=OUT;
    if(c=='\n')
      ++nl;
    goto Loop;
    
}