#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define BUFFERSIZE 256
int main(){
    char buffer[BUFFERSIZE];
    int i,j;
    bool isPalidrome;
    scanf("%[^\n]s",buffer);
    i = 0;
    j = strlen(buffer)-1;
    isPalidrome = true;
    while(i<=j){

        if('A'<=buffer[i] && buffer[i]<='Z'){
            buffer[i] = buffer[i] - 'A' + 'a';
        }
        if('A'<=buffer[j] && buffer[j]<='Z'){
            buffer[j] = buffer[j] - 'A' + 'a';
        }
        if(!('a' <= buffer[i] && buffer[i] <= 'z')){
            // printf("i++\n");
            i++;
            continue;
        }
        if(!('a' <= buffer[j] && buffer[j] <= 'z')){
            // printf("j--\n");
            j--;
            continue;
        }

        if(buffer[i]==buffer[j]){
            i++;
            j--;
        }else{
            isPalidrome = false;
            break;
        }
        
    }
    printf("%s\n",isPalidrome?"yes":"no");
}