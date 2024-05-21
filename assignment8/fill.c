#include <stdio.h>
#include <stdlib.h>

void printDrawing(char **arr,int m){
    int i;
    for(i=0;i<m;i++){
        printf("%s\n",arr[i]);
    }
}

void dfs_fill(char **arr,int pi,int pj,int m,int n,char a,char c){
    int i,j;
    int ni,nj;
    arr[pi][pj] = c;
    for(i=-1;i<=1;i++){
        for(j=-1;j<=1;j++){
            ni = pi+i;
            nj = pj+j;
            if(i!=j && i!=-j && ni>=0 && nj>=0 && ni<m && nj<n && arr[ni][nj]==a){
                dfs_fill(arr,ni,nj,m,n,a,c);
            }
        }
    }
}

int main(){
    int i,m,n,q;
    int pi,pj;
    char a,c;
    char **arr;
    scanf("%d %d",&m,&n);
    arr = malloc(sizeof(char*)*m);
    for(i=0;i<m;i++){
        arr[i] = malloc(sizeof(char)*(n+1));
        scanf("%s",arr[i]);
    }
    scanf("%d",&q);

    for(i=0;i<q;i++){
        scanf("%d %d %c",&pi,&pj,&c);
        a = arr[pi][pj];
        dfs_fill(arr,pi,pj,m,n,a,c);
    }

    printDrawing(arr,m);

    for(i=0;i<m;i++){
        free(arr[i]);
    }
    free(arr);
    return 0;
}