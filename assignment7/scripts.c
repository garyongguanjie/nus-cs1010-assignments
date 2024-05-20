#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,i,l,r;
    int *arr;
    int *output;

    scanf("%d",&n);
    arr = malloc(n*sizeof(int));
    output = malloc(n*sizeof(int));

    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    l = 0;
    r = n-1;
    i=0;

    while(l<=r){
        if(arr[l]<arr[r]){
            output[i] = arr[l];
            l++;
        }else{
            output[i] = arr[r];
            r--;
        }
        i++;
    }
    for(i=0;i<n;i++){
        printf("%d ",output[i]);
    }
    printf("\n");

    free(arr);
    free(output);

}