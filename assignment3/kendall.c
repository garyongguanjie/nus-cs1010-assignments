#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,i,j,totalpairs,diffpairs;
    scanf("%d",&n);

    int *arr = malloc(sizeof(int)*(n));
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    totalpairs = 0;
    diffpairs = 0;

    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if (arr[i]>arr[j]){
                diffpairs++;
            }
            totalpairs++;
        }
    }
    printf("%lf\n",(double)diffpairs/(double)totalpairs);

    return 0;
}