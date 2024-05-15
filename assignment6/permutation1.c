#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){
    int n,i,j;
    int *l1;
    int *l2;
    bool *visited;

    scanf("%d",&n);
    l1 = (int *)malloc(sizeof(int)*n);
    l2 = (int *)malloc(sizeof(int)*n);
    visited = (bool *)calloc(n,sizeof(bool));

    for(i=0;i<n;i++){
        scanf("%d",&l1[i]);
    }
    for(i=0;i<n;i++){
        scanf("%d",&l2[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if (!visited[j] && l1[i]==l2[j]){
                visited[j] = true;
            }
        }
    }

    for(i=0;i<n;i++){
        if(!visited[i]){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}