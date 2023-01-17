// 1. Write a program to sort an array on n elements using both sequential and parallel merge sort(using Section). Record the difference in execution time.

#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

void merge(int a[],int l, int mid, int r){
    int n1 = mid - l + 1;
    int n2 = r  - mid;
    int aa[n1],bb[n2];
    int i,j,k;
    for(i = 0; i < n1;i++) aa[i] = a[l + i];
    for(i = 0; i < n2;i++) bb[i] = a[mid + i + 1];
    i = 0; j = 0; k = l;
    while (i < n1 && j < n2){
        if (aa[i] <= bb[j]){
            a[k++] = aa[i++];
        }
        else{
            a[k++] = bb[j++];
        }
    }
    while (i < n1)
    {a[k++] = aa[i++];}
    while (j < n2)
    {a[k++] = bb[j++];}
}
void mss(int a[],int l, int r){
    if (l < r){
        int mid = (r - l) / 2;
        mid += l;
        mss(a,l,mid);
        mss(a,mid + 1, r);
        merge(a,l,mid,r); 
    }
}
int main(){
    int n;
    printf("enter length of array:");
    scanf("%d",&n);
    int * a = (int *) malloc(n * sizeof(int));
    for(int i = 0; i < n;i++)
        {a[i] = rand() % 100;}
    printf("before sort\n");
    for(int i = 0; i < n;i++)
    printf("%d ",a[i]);
    printf("\n after sort \n");
    mss(a,0,n-1);
    for(int i = 0; i < n;i++)
    printf("%d ",a[i]);


}