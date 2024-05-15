#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define BUFFERSIZE 1000

int main(){
    char a[BUFFERSIZE];
    char b[BUFFERSIZE];
    int count[26] = {0};
    int i,alen,blen,c;
    bool hasPerm = false;
    scanf("%s",a);
    scanf("%s",b);
    alen = strlen(a);
    blen = strlen(b);

    if (alen>blen){
        printf("NO\n");
        return 0;
    }
    c = 0;
    for(i=0;i<alen;i++){
        count[a[i]-'a']++;
    }
    for(i=0;i<blen;i++){
        if (count[b[i]-'a']>0){
            c++;
        }
        if (alen>=i && count[b[i-alen]-'a']>0){
            c--;
        }
        if(c==alen){
            hasPerm = true;
        }
        count[b[i]-'a']--;
        count[b[i-alen]-'a']--;
    }
    if(hasPerm){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}