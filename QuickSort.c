#include<stdio.h>

void swap(int* A,int* B)
{
    int temp=*A;
    *A=*B;
    *B=temp;
}

int partition(int*A,int l,int r)

{  
    int pivot=l;
    l++;
    
    // printf("%d-pivot\n",pivot);
    
    while(l<=r)
    {
        while(A[pivot]>A[l])
        l++;
        while(A[pivot]<A[r])
        r--;
        
        // printf("swapping %d at i=%d and %d at j=%d\n",A[i],i,A[j],j);
        swap(&A[l],&A[r]);
    }

        swap(&A[l],&A[r]);
        // printf("swapping %d and %d at j=%d\n",pivot,A[j],j);
        // int partition=j;
        swap(&A[pivot],&A[r]);
        return r;

}
void quicksort(int *A,int l,int r)
{
   if(l<r){ int p=partition(A,l,r);
    printf("%d-p\n",p);
    quicksort(A,l,p-1);
    quicksort(A,p+1,r);
   }
}


int main(){

    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int A[n];
    printf("enter the elements: ");
    for(int i=0;i<n;i++)
    scanf("%d",&A[i]);
     

    quicksort(A,0,n-1);

    printf("elements after swapping: ");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",A[i]);
    }
}