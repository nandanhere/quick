// 4.	Write a MPI program to find factorial of a number using Broadcast and Reduce operation.


#include<stdio.h>
#include<string.h>
#include<mpi.h>

int main () {
	int comm_sz;
	int my_rank;
    int fact, lower, upper, i;
    double local_result = 1.0,total;

	MPI_Init (NULL, NULL); 
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank); 

    if(my_rank == 0){
        printf("Enter number:");scanf("%d",&fact);
    }
    MPI_Bcast(&fact,1, MPI_INT,0,MPI_COMM_WORLD);
    // int MPI_Bcast(void *buffer, int count, MPI_Datatype datatype,
                            //  int root, MPI_Comm comm);
    if(my_rank == 0){
        lower = 1 ;
    }
    else{
        lower = my_rank * (fact / comm_sz) + 1;
    }
    if (my_rank == comm_sz - 1)
        upper = fact;
    else
        upper = (my_rank + 1) * (fact / comm_sz);

    for(i = lower ; i <= upper;i++){
        local_result = local_result * (double) i;
    }
    MPI_Reduce(&local_result
                ,&total,
                1,
                MPI_DOUBLE,
                MPI_PROD,
                0,
                MPI_COMM_WORLD);
                if(my_rank==0){
        printf("The factorial of %d is %lf, and was calculated using %d processes\n",fact,total,comm_sz);
    }
    MPI_Finalize();
    }