#include <stdio.h>

void draw_square(long row, long width){
    if(width==0){
    }
    else if(width==1){
        printf("#");
    }
    else if(width==2){
        printf("##");
    }
    else if(width==3){
        if (row==1){
            printf("# #");
        }else{
            printf("###");
        }
    }else{
        if(row==0 || row==width-1){
            for(int i=0;i<width;i++){
                printf("#");
            }
        }else{
            printf("#");
            if(row==1||row==width-2){
                for(int i=0;i<width-2;i++){
                    printf(" ");
                }
            }else{
                printf(" ");
                draw_square(row-2,width-4);
                printf(" ");
            }
            printf("#");
        }
    }
}


int main()
{
    long n;
    scanf("%ld",&n);
    for (long i = 0; i < n; i += 1)
    {
        draw_square(i, n);
        printf("\n");
    }
}