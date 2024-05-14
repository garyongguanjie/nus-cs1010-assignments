#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n);
// this problem is hard to understand in english
int main(){
    int n,h,i,j,k,p,numCols,center,leadingcell,inc,startingno,prevstartingno;
    bool hasPrime;
    scanf("%d %d",&n,&h);
    numCols = 2*h-1;
    center = numCols/2;
    startingno = 1;
    prevstartingno = 0;
    for(i=0;i<h;i++){
        // calculate leading cell position
        leadingcell = center - i;
        for (j=0;j<leadingcell;j++){
            putchar(' ');
        }
        inc = i+1;
        // generate 2h-a characters
        for(j=0;j<2*(i+1)-1;j++){
            hasPrime = false;
            for(k=0;k<n;k++){
                p = startingno + inc*k + j;
                // printf("%d, ",p);
                if (isPrime(p)){
                    hasPrime = true;
                }
            }
            // printf("|");
            if (hasPrime){
                putchar('#');
            }else{
                putchar(' ');
            }
            if(j==0){
                prevstartingno = p;
            }
        }
        startingno = prevstartingno + inc;
        putchar('\n');
    }
    return 0;
}

bool isPrime(int n){
    int i;
    if (n<2){
        return false;
    }
    for(int i=2;i<n;i++){
        if (n%i==0){
            return false;
        }
    }
    return true;
}