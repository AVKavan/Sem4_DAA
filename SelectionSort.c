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
void selsort(int a[], int n)
{  int min,temp;
    for(int i=0;i<n-1;i++)
    {    min=i;
        for(int j=i+1;j<n;j++)
        {
           if(a[j]<a[min])
           min=j;
        }
        // temp=a[i];
        //     a[i]=a[min];
        //     a[min]=temp;
            swap(&a[min],&a[i]);
    }
}

int main()
{   int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements of the array: ");
    for(int i=0;i<n;i++)
    {
        // scanf("%d",&arr[i]);
        arr[i]=rand();
    }
 printf("elements before swapping: ");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    start=clock();
    selsort(arr,n);
    end=clock();
    printf("elements after swapping: ");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    Ttime=(double)(end-start)/CLOCKS_PER_SEC;
    printf("the total time taken is: %lf",Ttime);
}