#include <stdio.h>
#include <stdbool.h>

bool isleapyear(int y);
void testLeapYear();

int main(){
    // key formula is to calculate number of days from  January 1, 1900 -> Monday
    // to current date then modulo 7;
    int i,y,m,d,ndays=0;

    scanf("%d %d %d",&y,&m,&d);
    int daysinmonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    char *weekday[] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    // calculate ndays based on year
    for (i=1900;i<y;i++){
        ndays += 365 + isleapyear(i);
    }
    // calculate days based on month of curr year
    for(i=1;i<m;i++){
        if (i==2 && isleapyear(y)){
            ndays += 29;
        }else{
            ndays += daysinmonth[i];
        }
    }
    ndays += d-1;
    printf("%s\n",weekday[ndays%7]);
    return 0;
}

void testLeapYear(){
    bool a,b,c,d;
    a = isleapyear(1995);
    b = isleapyear(1996);
    c = isleapyear(1900);
    d = isleapyear(2000);
    printf("%d %d %d %d\n",a,b,c,d);
}

bool isleapyear(int y){
    // with the exception of years divisible by 100 but not by 400
    if (y%100==0 && y%400!=0){
        return false;
    }
    return y%4==0;
}