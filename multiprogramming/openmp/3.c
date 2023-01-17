// 3.	Write an OpenMP program that divides the Iterations into chunks containing 2 iterations, respectively (OMP_SCHEDULE=static,2). Its input should be the number of iterations, and its output should be which iterations of a parallelized for loop are executed by which thread. For example, if there are two threads and four iterations, the output might be the following:
// 	Thread 0 : Iterations 0 −− 1
// 	Thread 1 : Iterations 2 −− 3

#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(){
    omp_set_num_threads(10);
    int start[10],end[10];
    int i;
    for(i = 0; i < 10;i++){
        start[i] = end[i] = 0;
    }
    
    #pragma omp parallel for schedule(static,3)
    for( i = 1; i <= 30;i++){
        int x = omp_get_thread_num();
        if (start[x]){
            end[x] = i;
        }
        else{
            start[x] = i;
        }
    }
    for(i = 0; i < 10;i++){
        printf("thread: %d, %d -> %d\n",i,start[i],end[i]);
    }
    return 0;
}