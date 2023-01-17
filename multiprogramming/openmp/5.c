// 5.	Write a program to find the prime numbers from 1 to n employing parallel for directive. Record both serial and parallel execution times.
#include<stdio.h>
#include<omp.h>
#include<time.h>
#include<stdlib.h>

int main(){
    int prime[1000],i,j,n;
    omp_set_num_threads(10);
       
    printf("Enter the n\n");
    scanf("%d",&n);

    for(i = 1; i < n ; i ++)
        prime[i] = 1;
    for (i = 2; i * i <= n;i++){
        if  (prime[i] == 1)
        #pragma omp parallel for
        for (j = i * i; j < n; j += i){
            if (prime[j] == 1){
                prime[j] = 0;
            }
        }
    }

    // #pragma omp parallel for
    for (i = 2; i <= n ;i++){
        if (prime[i])
            printf("%d\t",i);
    }
    printf("\n");
    return 0;
}