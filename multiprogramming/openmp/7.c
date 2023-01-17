// 7.	Write a program   calculate the sum of first 100 Numbers. (Using critical directive)


#include<stdio.h>
#include<omp.h>

int main(){
    int sum = 0;
    int i = 0;
    double a = omp_get_wtime();
    #pragma omp parallel for
    for (i = 1; i <= 100; i++){
        #pragma omp critical
        sum += i;
    }
    printf("Sum is %d\n",sum);
    printf("time was %lf\n",omp_get_wtime() - a);
     sum = 0;
     i = 0;
     a = omp_get_wtime();
    for (i = 1; i <= 100; i++){
        sum += i;
    }
    printf("Sum is %d\n",sum);
    printf("time was %lf\n",omp_get_wtime() - a);
}
