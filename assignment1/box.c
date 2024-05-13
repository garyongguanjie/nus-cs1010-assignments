#include <stdio.h>
#include <math.h>

int main(){
    long l,w,h;
    long surfaceArea = 0;
    double flatDiag;
    double diagonalLength;
    scanf("%ld %ld %ld",&l,&w,&h);
    surfaceArea = l*w*2 + l*h*2 + w*h*2;
    diagonalLength = sqrt(l*l+w*w+h*h);
    printf("%ld %lf\n",surfaceArea,diagonalLength);
}