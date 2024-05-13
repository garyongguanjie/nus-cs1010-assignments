#include <stdio.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

int getminute(int h,int m);
int roundUpDiv(int a,int b);
int main(){
    int day,h,m,dist;
    int currMin = getminute(h,m);
    double surcharge = 1;
    // The first 1 km or less (Flag Down)	$3.40
    double fare = 3.4;
    scanf("%d %d %d %d",&day,&h,&m,&dist);

    if ((day>=1 && day<=5 && currMin>=getminute(6,0) && currMin<=getminute(9,29)) || 
        (currMin>=getminute(18,0) && currMin<=getminute(23,59))){
            surcharge = 1.25;
        }
    if (currMin>=0 && currMin<=getminute(5,59)){
        surcharge = 1.5;
    }
    if (dist>1000){
        // Every 400 m thereafter or less, up to 10.2 km	$0.22
        // from 1km -> 10.2km $0.22
        fare += 0.22*roundUpDiv((MIN(10200,dist)-1000),400);
        
        // Every 350 m thereafter or less, after 10.2 km	$0.22
        if (dist>10200){
            fare +=  0.22 * roundUpDiv((dist - 10200),350);
        }
    }
    printf("%lf\n",fare*surcharge);
}

int getminute(int h,int m){
    return h*60 + m;
}

int roundUpDiv(int a,int b){
    return a%b ? a/b+1 : a/b;
}