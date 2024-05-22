#include <stdio.h>
#include <stdlib.h>
// professor might be wrong in time complexity analysis
int main(){
    int j,i,n;
    int *sieveCount;
    int npairs;
    scanf("%d",&n);
    sieveCount = calloc(n,sizeof(int));
    // O(nloglogn)
    for(i=2;i<n;i++){
        if(sieveCount[i]==0){
            for(j=2*i;j<n;j+=i){
                sieveCount[j]++;
            }
            if(i*i<n){
                sieveCount[i*i]++;
            }
        }
    }
    npairs = 0;
    int complement;
    // O(n)
    for(i=2;i<n;i++){
        if(sieveCount[i]==0){
            complement = n-i;
            if(complement<n && sieveCount[complement]==2){
                npairs++;
            }
        }   
    }
    free(sieveCount);
    printf("%d\n",npairs);
}