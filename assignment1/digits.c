#include <stdio.h>
// You should not use a loop to solve this, 
// but rather, you should write a function sum_of_digits 
// that takes in an integer and return the sum of the digits of that integer, 
// that calls itself

unsigned sum_of_digits(unsigned d);

int main(){
    unsigned int d;
    scanf("%u",&d);

    printf("%u\n",sum_of_digits(d));

}

unsigned sum_of_digits(unsigned d){
    if(d==0)
        return 0;
    return d%10 + sum_of_digits(d/10);
}