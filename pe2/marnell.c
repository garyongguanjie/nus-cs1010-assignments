#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define PRIME 1
#define SEMIPRIME 2
#define NEITHER 3

bool isPrime(int n){
    if(n<2){
        return false;
    }
    int i;
    for(i=2;i<=sqrt(n);i++){
        if (n%i==0){
            return false;
        }
    }
    return true;
}

int isPrimeSemiPrimeNeither(int n){
    int i;
    bool a,b;
    for(i=2;i<=sqrt(n);i++){
        if(n%i==0){
            a = isPrime(i);
            b = isPrime(n/i);
            if(a&&b){
                // printf("%d %d\n",i,n/i);
                return SEMIPRIME;
            }
            return NEITHER;
        }
    }
    return PRIME;
}

int main(){
    int i,n,complement,a,b;
    scanf("%d",&n);
    int npairs;
    npairs =0;
    for(i=2;i<=n/2;i++){
        complement = n-i;
        a = isPrimeSemiPrimeNeither(i);
        b = isPrimeSemiPrimeNeither(complement);
        if((a==PRIME && b==SEMIPRIME) || (a==SEMIPRIME && b==PRIME)){
            // printf("%d %d\n",i,complement);
            npairs++;
        }
    }
    
    printf("%d\n",npairs);
}