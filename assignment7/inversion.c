#include <stdio.h>
#include <stdlib.h>

#define abs(x)  ( ( (x) < 0) ? -(x) : (x) )

int main(){
    int n,i,l,r,ninversions,p,maxV;
    int *arr;
    scanf("%d",&n);
    arr = malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    l = 0;
    r = n-1;
    i = 0;
    ninversions = 0;
    while(l<r){
        if(arr[l]<arr[r]){
            // shifting left pointer means nothing out of order?
            l++;
        }else{
            // need count number of shit out of order
            ninversions += r-l;
            r--;
        }
        i++;
    }
    printf("%d\n",ninversions);
}