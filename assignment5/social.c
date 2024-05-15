#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void dfs(bool* visited,int a,char** graph,int n,int k);

int main(){
    int i,j,n,k;
    bool allconnected = true;
    scanf("%d %d",&n,&k);

    char **graph = (char **) malloc(sizeof(char*)*n);
    bool *visited = (bool *) malloc(sizeof(bool)*n);
    char **currp = graph;
    char *a;
    for(i=0;i<n;i++){
        a = (char *)malloc(sizeof(char)*(i+1));
        scanf("%s",a);
        *currp = a;
        currp++;
    }
    memset(visited,false,sizeof(bool)*n);
    dfs(visited,0,graph,n,k);
    for(i=0;i<n;i++){
        if(!visited[i]){
            allconnected = false;
        }
        for(j=0;j<=i;j++){
            if(visited[i]){
                graph[i][j] = '1';
            }
            
        }
    }
    for(i=0;i<n;i++){
        printf("%s\n",graph[i]);
    }

    allconnected ? printf("YES\n"):printf("NO\n");
    return 0;
}

void dfs(bool* visited,int a,char** graph,int n,int k){
    int i,j;
    // printf("visiting=%d, visited=%d n=%d, k=%d\n",a,visited[a],n,k);
    if (visited[a] || k<0){
        return;
    }
    visited[a] = true;
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            if(i!=j){
                if(i==a && graph[i][j]=='1'){
                    dfs(visited,j,graph,n,k-1);
                }else if(j==a && graph[i][j]=='1'){
                    dfs(visited,i,graph,n,k-1);
                }
            }
        }
    }
}
