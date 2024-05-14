#include <stdio.h>
#include <stdlib.h>

int main(){
    int i,j,n,temp,maxVal,maxJ;
    scanf("%d",&n);
    int *arr = malloc(sizeof(int)*n);

    for (i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(i=n-1;i>=1;i--){
        maxVal = arr[i];
        maxJ = i;
        for(j=0;j<i;j++){
            if (arr[j]>maxVal){
                maxJ = j;
                maxVal = arr[j];
            }
        }
        if(maxJ!=i){
            temp = arr[maxJ];
            arr[maxJ] = arr[i];
            arr[i] = temp;
        }
        for(j=0;j<n;j++){
            printf("%d ",arr[j]);
        }
        printf("\n");
    }
    return 0;
}