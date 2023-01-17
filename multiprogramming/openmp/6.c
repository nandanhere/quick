// 6.	Parallel Vector Addition
#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
    int vectorsize;
    printf("enter the vector size : ");
    scanf("%d",&vectorsize);
    int * a1 = (int * ) malloc(sizeof(int) * vectorsize);
    int * b1 = (int * ) malloc(sizeof(int) * vectorsize);
    int * result = (int * ) malloc(sizeof(int) * vectorsize);
    printf("enter the vectors\na1:");
    for (int i = 0;i< vectorsize;i++)
        scanf("%d",&a1[i]);
    printf("enter the vector b1:");
    for (int i = 0;i< vectorsize;i++)
        scanf("%d",&b1[i]);
    #pragma omp paralell for
    for (int i = 0;i< vectorsize;i++){
        result[i] = a1[i] + b1[i];
    }
    printf("vector sum are:");
    for (int i = 0;i< vectorsize;i++){
    printf("%d ",result[i]);
    }
        printf("\n");
    a1[vectorsize - 1] = 10;
    printf("%d",a1[vectorsize - 1]);
}