#include <stdio.h>



int main(){
    long N,n,largestn;
    int i,stoppingtime,longeststoppingtime=0;
    
    scanf("%ld",&N);

    for (i=1;i<=N;i++){
        n = i;
        stoppingtime = 0;
        while(n!=1){
            n = (n%2) ? 3*n+1 :n/2;
            stoppingtime++;
        }
        if (stoppingtime>=longeststoppingtime){
            longeststoppingtime = stoppingtime;
            largestn = i;
        }
    }
    
    printf("%ld\n",largestn);
    printf("%d\n",longeststoppingtime);
    return 0;
}