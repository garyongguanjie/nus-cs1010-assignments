#include <stdio.h>
#include <string.h>
#define BUFFERSIZE 1000

int main(){
    char a[BUFFERSIZE];
    char b[BUFFERSIZE];
    int count[26] = {0};
    int i,alen,blen;
    scanf("%s",a);
    scanf("%s",b);
    alen = strlen(a);
    blen = strlen(b);
    if(alen!=blen){
        printf("NO\n");
        return 0;
    }

    for(i=0;i<alen;i++){
        count[a[i]-'a']++;
        count[b[i]-'a']--;
    }

    for(i=0;i<26;i++){
        if(count[i]!=0){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
}