#include <stdio.h>
#include <stdlib.h>

#define min(a, b) ( (a) < (b) ? ( a ) : ( b ) )

int main(){
    long n;
    int prevd,d,maxd;
    int c,maxc;
    scanf("%ld",&n);
    maxc = 0;
    c = 0;
    prevd = d % 10;
    while(n){
        d = n%10;
        if (d==prevd){
            c+=1;
            if(c>maxc){
                maxc = c;
                maxd = d;
            }else if (c==maxc){
                maxd = min(maxd,d);
            }
            
        }else{
            c = 0;
        }
        prevd = d;
        n/=10;
    }
    printf("%d\n",maxd);
}