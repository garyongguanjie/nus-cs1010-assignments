#include <stdio.h>

#define abs(x)  ( ( (x) < 0) ? -(x) : (x) )

int main(){
    double a,b,c,d,xi,fxi,dfxi;
    scanf("%lf %lf %lf %lf %lf",&a,&b,&c,&d,&xi);
    fxi = a *xi*xi*xi + b*xi*xi + c*xi + d;
    dfxi = 3*a*xi*xi + 2*b*xi+c;

    while(abs(fxi)>=0.000000001){
        fxi = a *xi*xi*xi + b*xi*xi + c*xi + d;
        dfxi = 3*a*xi*xi + 2*b*xi+c;
        xi = xi - fxi/dfxi;
    }
    printf("%.4lf\n",xi);
}