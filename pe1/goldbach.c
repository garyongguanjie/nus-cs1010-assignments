#include <stdio.h>
#include <stdlib.h>

int main(){
    int i,n,j,complement;
    int *arr;
    int npairs=0;
    scanf("%d",&n);

    // find all prime numbers lower than n
    arr = calloc(n,sizeof(int));
    for(i=2;i<n;i++){
        if(!arr[i]){
            for(j=2*i;j<n;j+=i){
                arr[j]=1;
            }
        }
    }
    arr[0] = 1;
    arr[1] = 1;
    // all primes are = 0;
    // not sure how to handle case of repition??
    for(i=2;i<n/2+1;i++){
        complement = n-i;
        if (arr[i]==0 && arr[complement]==0){
            npairs++;
        }
    }
    printf("%d\n",npairs);
}