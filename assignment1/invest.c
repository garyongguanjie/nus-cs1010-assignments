#include <stdio.h>
#include <math.h>

int main(){
    int m,r,n,i;
    scanf("%d %d %d",&m,&r,&n);

    printf("%lf\n",(m*(1-pow((double)r/100,n+1))/(1-(double)r/100)));
    return 0;
}