#include <stdio.h>
#include <math.h>
int main(){
    int buckets[10] = {0};
    int n,i,j,score,c;
    double l;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d",&score);
        if(score==100){
            score-=1;
        }
        buckets[score/10]++;
    }
    printf("          ┴┴┴┴┴┴┴┴┴┴\n");
    for(i=0;i<100;i+=10){
        printf("%2d - %3d",i,i+10);
        c = buckets[i/10]*100;
        l = (double)c/n/10;
        printf("  ");
        // printf("%lf",l);
        if (c%n==0 && c/n%10==0){
            for(j=0;j<l;j++){
                printf("█");
            }
        }else if (l-floor(l)<0.5){
            for(j=0;j<l;j++){
                printf("█");
            }
            printf("▌");
        }else{
            for(j=0;j<l+1;j++){
                printf("█");
            }
        }
        printf("\n");
    }
}