#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

void printMaze(char **arr,int m,int *steps){
    char clear_screen[] = { 27, '[', '2', 'J',27, '[', ';', 'H', '\0'};
    printf("%s",clear_screen);
    int i;
    for (i=0;i<m;i++){
        printf("%s\n",arr[i]);
    }
    printf("%d\n",*steps);
    
    usleep(250*1000);
    (*steps)++;
}

bool dfs(char** arr,bool** visited,int pi,int pj,int m,int n,int *steps){
    bool solved=false;
    arr[pi][pj] = '@';
    printMaze(arr,m,steps);
    if ((pi==0||pi==m-1||pj==0||pj==n-1)){
        return true;
    }
    visited[pi][pj] = true;
    // up
    if (pi-1>=0 && arr[pi-1][pj]!='#' && !visited[pi-1][pj]){
        arr[pi][pj] = '.';
        solved = dfs(arr,visited,pi-1,pj,m,n,steps);
        if(!solved){
            // printbacktracking path
            arr[pi-1][pj] = '.';
            arr[pi][pj] = '@';
            printMaze(arr,m,steps);
        }
    }
    // right
    if(!solved && pj+1<n && arr[pi][pj+1]!='#'  && !visited[pi][pj+1]){
        arr[pi][pj] = '.';
        solved = dfs(arr,visited,pi,pj+1,m,n,steps);
        if(!solved){
            // printbacktracking path
            arr[pi][pj+1] = '.';
            arr[pi][pj] = '@';
            printMaze(arr,m,steps);
        }
    }
    // down
    if(!solved && pi+1<m && arr[pi+1][pj]!='#' && !visited[pi+1][pj]){
        arr[pi][pj] = '.';
        solved = dfs(arr,visited,pi+1,pj,m,n,steps);
        if(!solved){
            // printbacktracking path
            arr[pi+1][pj] = '.';
            arr[pi][pj] = '@';
            printMaze(arr,m,steps);
        }
    }
    // left
    if(!solved && pj-1>=0 && arr[pi][pj-1]!='#' && !visited[pi][pj-1]){
        arr[pi][pj] = '.';
        solved = dfs(arr,visited,pi,pj-1,m,n,steps);
        if(!solved){
            // printbacktracking path
            arr[pi][pj-1] = '.';
            arr[pi][pj] = '@';
            printMaze(arr,m,steps);
        }
    }
    arr[pi][pj] = '.';
    return solved;
}

int main(){
    int pi,pj,i,j,m,n;
    char **arr;
    bool **visited;
    int steps = 0;
    scanf("%d %d",&m,&n);
    arr = malloc(sizeof(char*)*m);
    visited = malloc(sizeof(bool*)*m);

    for(i=0;i<m;i++){
        arr[i] = malloc(sizeof(char)*(n+1));
        visited[i] = calloc(n,sizeof(bool));
        scanf("%s",arr[i]);
    }
    pi=0;
    pj=0;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if (arr[i][j]=='@'){
                pi = i;
                pj = j;
            }
        }
    }

    
    printf("reached... pi:%d pj:%d\n",pi,pj);
    dfs(arr,visited,pi,pj,m,n,&steps);

    for(i=0;i<m;i++){
        free(arr[i]);
        free(visited[i]);
    }
    free(arr);
    free(visited);
}