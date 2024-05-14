#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,k,i,x,j;
    scanf("%d %d",&n,&k);

    int *arr = calloc(k+1,sizeof(int));

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        if (x>=1&&x<=k){
            arr[x]++;
        }
    }
    for (int i=1;i<=k;i++){
        if(arr[i]){
            for(j=0;j<arr[i];j++){
                printf("%d\n",i);
            }
        }
    }
}