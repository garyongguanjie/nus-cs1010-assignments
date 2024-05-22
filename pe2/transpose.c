#include <stdio.h>
#include <stdlib.h>

void transpose_matrix(double **m1, double **m2, long nrows, long ncols);

int main(){
    long i,j,m,n;
    double **m1;
    double **m2;
    scanf("%ld %ld",&m,&n);
    m1 = malloc(sizeof(double*)*m);
    m2 = malloc(sizeof(double*)*n);
    for(i=0;i<m;i++){
        m1[i] = malloc(sizeof(double)*n);
        for(j=0;j<n;j++){
            scanf("%lf",&m1[i][j]);
        }
    }
    for(j=0;j<n;j++){
        m2[j] = malloc(sizeof(double)*m);
    }
    transpose_matrix(m1,m2,m,n);
    

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%.4lf ",m2[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<m;i++){
        free(m1[i]);
    }
    for(j=0;j<n;j++){
        free(m2[j]);
    }

    free(m1);
    free(m2);
}

void transpose_matrix(double **m1, double **m2, long nrows, long ncols){
    int i,j;
    for(i=0;i<nrows;i++){
        for(j=0;j<ncols;j++){
            m2[j][i] = m1[i][j];
        }
    }
}