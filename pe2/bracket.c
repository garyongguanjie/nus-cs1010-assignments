#include <stdio.h>
#include <stdbool.h>

#define BUFFERSIZE 256

int main(){
    int i,len;
    char buffer[256];
    scanf("%s",buffer);
    len = strlen(buffer);

    // 4 types of brackets (,[,<,{
    // their closing       ),],>,}
    // NOTE: You must solve this problem using recursion.
    // <>([])
    // ((())<>[]){}
    // <(>)
}