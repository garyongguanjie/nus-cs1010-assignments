#include <stdio.h>
#include <stdlib.h>
// that a peak is a location that is strictly higher than the surrounding locations
int main(){
    int i,n,l,r,m,ans;
    int *arr;
    
    scanf("%d",&n);
    arr = malloc(n*sizeof(int));
    for (i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    ans = -1;
    l = 0;
    r = n-1;

    while(l<=r){
        m = (l+r)/2;
        // printf("l:%d,r:%d,m:%d\n",l,r,m);
        // printf("arr[m-1]=%d arr[m]=%d  arr[m+1]=%d \n",arr[m-1],arr[m],arr[m+1]);
        if (arr[m-1]<arr[m] && arr[m]>arr[m+1] && m!=n-1 && m!=0){
            
            ans = m;
            break;
        }else if(arr[m]<arr[m+1]){
            l = m + 1;
        }else{
            r = m - 1;
        }
    }
    if(ans!=-1){
        printf("%d\n",ans);
    }else{
        printf("no peak\n");
    }
    free(arr);
    return 0;
}