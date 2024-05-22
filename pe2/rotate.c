#include <stdio.h>
#include <stdlib.h>

int main(){
    int i,n,q;
    int *arr;
    scanf("%d",&n);
    arr = malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&q);
    int l,r,mid;
    int index = -1;
    l = 0;
    r = n-1;

    while(l<=r){
        mid = (l+r)/2;
        if(arr[mid]==q){
            index = mid;
            break;
        }
        // at least one part must be sorted
        if(arr[mid]<arr[r]){
            // if right part is sorted
            // check if q is in the sorted part
            if(arr[mid]<q && q<=arr[r]){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }else{// left part is sorted here
            // check if q is in the sorted part
            if(arr[l]<=q && arr[mid]<q){
                r = mid -1;
            }else{
                l = mid +1;
            }
        }
    }

    if(index>=0){
        printf("%d\n",index);
    }else{
        printf("not found\n");
    }
    free(arr);
}