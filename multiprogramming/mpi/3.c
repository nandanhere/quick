// 3.	Write a MPI program to implement Vector Addition of two vectors to generate resultant vector using Scatter and gather operation.

// mpirun -np 10 --oversubscribe ./a.out 
//use oversubscribe if it fails for higher number of np
#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

int main(){
    int comm_size,rank,n,subn;
    int * v1,* v2,* sumv,* v1small, * v2small, * sumsmall;
    n = 10;
    MPI_Init(NULL,NULL);
    MPI_Comm_size(MPI_COMM_WORLD,&comm_size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);

    if (rank == 0){
            printf("Comm_size is %d\n",comm_size);
     v1 = (int * )malloc(n * sizeof(int));
    v2 = (int * )malloc(n * sizeof(int));
     sumv = (int * )malloc(n * sizeof(int));

    for (int i  = 0; i < n;i++) v1[i] = rand() % 100;
    for (int i  = 0; i < n;i++) v2[i] = rand() % 100;
    for (int i  = 0; i < n;i++) printf("%d ",v1[i]);
    printf("\n");
    for (int i  = 0; i < n;i++) printf("%d ",v2[i]);
        printf("\n");
    }

    subn = n / comm_size;
    if(subn == 0) subn = 1;
     v1small = (int * ) malloc(subn * sizeof(int));
 v2small = (int * ) malloc(subn * sizeof(int));
    MPI_Scatter(v1,subn,MPI_INT, v1small, subn,MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(v2,subn,MPI_INT, v2small, subn,MPI_INT, 0, MPI_COMM_WORLD);
    // int MPI_Scatter(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                            //    void *recvbuf, int recvcount, MPI_Datatype recvtype,
                            //    int root, MPI_Comm comm);

    sumsmall = (int * ) malloc(subn * sizeof(int));
    for(int i = 0; i < subn;i++){
        sumsmall[i] = v1small[i] + v2small[i];
    }
    MPI_Gather(sumsmall,subn,MPI_INT, sumv,subn,MPI_INT,0,MPI_COMM_WORLD);
    // int MPI_Gather(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
    //                           void *recvbuf, int recvcount, MPI_Datatype recvtype,
    //                           int root, MPI_Comm comm);
    if(rank == 0){
        printf("sum is \n");
    for (int i  = 0; i < n;i++) printf("%d ",sumv[i]);
    printf("\n");
    }


    MPI_Finalize();


}