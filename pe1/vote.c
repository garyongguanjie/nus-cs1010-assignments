#include <stdio.h>
#include <stdlib.h>

int main(){
    double a,b,total;
    scanf("%lf %lf",&a,&b);
    total = a + b;
    printf("%.4lf %.4lf\n",a*100/total,b*100/total);
}