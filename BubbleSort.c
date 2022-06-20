#include<stdio.h>
#include<stdlib.h>
#include<time.h>
clock_t start,end;
double Ttime;


void swap(int* n, int* m)
{
    int temp=*n;
    *n=*m;
    *m=temp;
}
void bubblesort(int a[],int n)
{    int temp;
    for(int i=0;i<n-1;i++)
    for(int j=0;j<n-1-i;j++)
    {
        if(a[j]>a[j+1])
        {//temp=a[j];
        //     a[j]=a[j+1];
        //     a[j+1]=temp;
        swap(&a[j],&a[j+1]);
        }
    }
}


int main()
{
    int n;
    printf("enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elments of the array:\n ");
    for(int i=0;i<n;i++)
    {
        arr[i]=rand()%1000;
    }
    printf("elements before swapping: ");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    start=clock();
    bubblesort(arr,n);
    end=clock();

     printf("\nelements after swapping: ");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }

    Ttime=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\n total time taken is: %lf",Ttime);
}