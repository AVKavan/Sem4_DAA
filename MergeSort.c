#include<stdio.h>


void merge(int* B,int* C,int l,int r,int n,int* A)
{
    int i=0,j=0,k=0;

    while(i<l && j<r)
    {
        if(B[i]<=C[j])
         {A[k]=B[i]; i++;}
        else
        {A[k]=C[j]; j++;}

        k++;
    }

    while(i<l)
    {
        A[k]=B[i];
        i++;
        k++;
    }
    while(j<r)
    {
        A[k]=C[j];
        j++;
        k++;
    }
}

void mersort(int* A,int n)
{
    if(n>1)
    {
        int m=n/2;
        int l=m;
        int r=n-m;
        int B[l];
        int C[r];

        for(int i=0;i<l;i++)
        B[i]=A[i];
        for(int j=m;j<n;j++)
        C[j-m]=A[j];

        mersort(B,l);
        mersort(C,r);

        merge(B,C,l,r,n,A);
    }
}







int main()
{
    int n;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    int A[n];

    for(int i=0;i<n;i++)
    scanf("%d",&A[i]);

    mersort(A,n);

     printf("elements after swapping: ");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",A[i]);
    }
}