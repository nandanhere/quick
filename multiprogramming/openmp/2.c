
// 2.	Estimate the value of pi using:
//         pi = 4 * summation(k from 0 to infinity)((-1)^k / (2k + 1))
//     Parallelize the code by removing loop carried dependency and record both serial and parallel execution times.

#include<stdlib.h>
#include<stdio.h>
#include<omp.h>
#include<math.h>

#define inf 10000
int main(){
    float pi = 0;
    double start = omp_get_wtime();
    for(int k = 0; k < inf;k++){
        pi += pow(-1,k) / (2 * k + 1);
    }
    pi *= 4;
    printf("Value of pi %lf time it took for serial %lf\n",pi,omp_get_wtime() - start);
 pi = 0;
 start = omp_get_wtime();
 #pragma omp parallel for num_threads(10)
    for(int k = 0; k < inf;k++){
        #pragma omp critical
        pi += pow(-1,k) / (2 * k + 1);
    }
    pi *= 4;
    printf("Value of pi %lf time it took for paralell %lf",pi,omp_get_wtime() - start);
}