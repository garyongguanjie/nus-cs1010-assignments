#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int i,j,r,nrows,dx,dy;
    double d,dxy;
    scanf("%d",&r);
    nrows = 2*r+1;

    for(i=0;i<nrows;i++){
        for(j=0;j<nrows;j++){
            dy = abs(j-r);
            dx = abs(i-r);
            d = sqrt(dy*dy+dx*dx);
            dxy = d-r;
            // printf("%lf\n",dxy);
            if (fabs(dxy)<0.1){
                putchar('@');
            }else if (fabs(dxy)<0.3){
                putchar('O');
            }else if (fabs(dxy)<0.5){
                putchar('*');
            }else if (fabs(dxy)<0.7){
                putchar('+');
            }else{
                putchar(' ');
            }
        }
        putchar('\n');
    }
    return 0;
}