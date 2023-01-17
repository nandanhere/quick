// 2.	Write a MPI program to demonstrate deadlock and implement a solution to avoid deadlock
#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char msg[100];
    char inbuffer[100];
    int size,rank,count;
    MPI_Init(NULL,NULL);
    MPI_Status stat;
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    
    if(rank == 0){
        MPI_Send(msg,100,MPI_CHAR,1,1,MPI_COMM_WORLD);
        MPI_Recv(inbuffer,100,MPI_CHAR,1,0,MPI_COMM_WORLD,&stat);

    }
    else if (rank == 1){
        MPI_Send(msg,100,MPI_CHAR,0,0,MPI_COMM_WORLD);
        MPI_Recv(inbuffer,100,MPI_CHAR,0,1,MPI_COMM_WORLD,&stat);
    }
    MPI_Get_count(&stat,MPI_CHAR,&count);
    printf("recieved %d characters from task %d with tag %d with message %s\n",count, stat.MPI_SOURCE,stat.MPI_TAG,inbuffer);
    MPI_Finalize();
}

















// int main(int argc,char *argv[])
// {
//     char outmsg[100]="Hey There!";
//     char inmsg[100];
//     int dest,source,rc,count,tag1=1,tag2=2;
//     MPI_Status stat;
//     MPI_Init(&argc,&argv);
//     int size,rank;
//     MPI_Comm_size(MPI_COMM_WORLD,&size);
//     MPI_Comm_rank(MPI_COMM_WORLD,&rank);
//     if(rank==0)
//     {
//         dest=1;
//         source=1;
//         rc=MPI_Send(&outmsg,strlen(outmsg),MPI_CHAR,dest,tag1,MPI_COMM_WORLD);
//         rc=MPI_Recv(&inmsg,strlen(outmsg),MPI_CHAR,dest,tag2,MPI_COMM_WORLD,&stat);
//     }
//     else if(rank==1)
//     {
//         dest=0;
//         source=0;
//         rc=MPI_Send(&outmsg,strlen(outmsg),MPI_CHAR,dest,tag2,MPI_COMM_WORLD);
//         rc=MPI_Recv(&inmsg,strlen(outmsg),MPI_CHAR,dest,tag1,MPI_COMM_WORLD,&stat);
//     }
//     rc=MPI_Get_count(&stat,MPI_CHAR,&count);
//     printf("Task %d, received %d char(s) task from %d with tag %d and msg is %s\n",rank,count,stat.MPI_SOURCE,stat.MPI_TAG,inmsg);
//     MPI_Finalize();
//     return 0;
// }