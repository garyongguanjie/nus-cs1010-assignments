#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){
    char code[4];
    char guess[4];
    bool codeMark[4];
    bool guessMark[4];
    int cpcc;// correct position correct color
    int ccnp;// correct color not position
    int i,j;
    scanf("%s",code);
    while(cpcc!=4){
        scanf("%s",guess);
        memset(codeMark,false,sizeof(codeMark));
        memset(guessMark,false,sizeof(guessMark));
        cpcc = 0;
        ccnp = 0;
        // calculate cpcc first
        for(i=0;i<4;i++){
            if(guess[i]==code[i]){
                cpcc++;
                codeMark[i] = true;
                guessMark[i] = true;
            }
        }

        // calculate correct color not position
        for (i=0;i<4;i++){
            for(j=0;j<4;j++){
                if (!guessMark[i] && !codeMark[j] && guess[i]==code[j]){
                    ccnp++;
                    guessMark[i] = true;
                    codeMark[j] = true;
                }
            }
        }
        printf("%d %d\n",cpcc,ccnp);
    }
    return 0;
}