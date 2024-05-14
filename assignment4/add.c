#include <stdio.h>
#include <string.h>
#define BUFFERSIZE 256

int main(){
    char str1[BUFFERSIZE];
    char str2[BUFFERSIZE];
    char result[BUFFERSIZE];
    int s,c,i,j,r,d1,d2;

    scanf("%s",str1);
    scanf("%s",str2);

    s = 0;
    c = 0;
    i=strlen(str1)-1;
    j=strlen(str2)-1;
    r=BUFFERSIZE-1;
    result[r--] = '\0';
    while(i>=0 && j>=0){
        d1 = str1[i--] - '0';
        d2 = str2[j--] - '0';
        s = d1 + d2 + c;
        c = s/10;
        s%=10;
        result[r--] = s + '0';
    }
    while(i>=0){
        d1 = str1[i--] - '0';
        s = d1 + c;
        c = s/10;
        s%=10;
        result[r--] = s + '0';
    }
    while(j>=0){
        d2 = str2[j--] - '0';
        s = d2 + c;
        c = s/10;
        s%=10;
        result[r--] = s + '0';
    }
    if (c>0){
        result[r--] = c + '0';
    }
    r++;
    printf("%s\n",&result[r]);
    return 0;
}
