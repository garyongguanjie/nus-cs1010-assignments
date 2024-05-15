#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
    char clear_screen[] = { 27, '[', '2', 'J',27, '[', ';', 'H'};
    int i,j,n,m,k,livenei,x,y;

    scanf("%d %d %d",&n,&m,&k);
    char **array = (char**)malloc(sizeof(char*)*n);
    char **array2 = (char**)malloc(sizeof(char*)*n);
    for (i=0;i<n;i++){
        array[i] = (char*)malloc(sizeof(char)*(m+1));
        scanf("%s",array[i]);
        array2[i] = (char*)malloc(sizeof(char)*(m+1));
        memcpy(array2[i],array[i],sizeof(char)*(m+1));
    }
    while(k--){
        for (i=0;i<n;i++){
            printf("%s\n",array[i]);
        }
        for(i=1;i<n-1;i++){
            for(j=1;j<m-1;j++){
                livenei = 0;
                for(x=-1;x<=1;x++){
                    for(y=-1;y<=1;y++){
                        if(!(x==0&&y==0) && array[i+x][j+y]=='#'){
                            livenei +=1;
                        }
                    }
                }
                // Any live cell with fewer than two live neighbors becomes dead
                // Any live cell with two or three live neighbors remains alive.
                // Any live cell with more than three live neighbors becomes dead.
                // Any dead cell with exactly three live neighbors becomes alive
                if (array[i][j]=='#' && livenei <2){
                    array2[i][j] = '.';
                }else if (array[i][j]=='#' && (livenei == 2 ||livenei==3) ){
                    array2[i][j] = '#';
                }else if (array[i][j]=='#' && livenei>3 ){
                    array2[i][j] = '.';
                }else if (array[i][j]=='.' && livenei==3){
                    array2[i][j] = '#';
                }else{
                    array2[i][j] = array[i][j];
                }
            }
        }
        
        for(i=0;i<n;i++){
            memcpy(array[i],array2[i],sizeof(char)*(m+1));
        }
        usleep(50*1000);
        printf("%s",clear_screen);
    }
}