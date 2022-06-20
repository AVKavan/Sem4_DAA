#include<stdio.h>

void print(int n,int(*A)[n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {printf("%d ",A[i][j]);}
        printf("\n");
    }
    
}

int min(int a,int b)
{
    return (a>b?b:a);
}

void warshall(int n,int(*A)[n])
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                A[i][j]= min(A[i][k] + A[k][j], A[i][j]);
            }
        }
    }
    printf("Transitive closure:\n");
   print(n,A);

}



void main()
{
    int n;
    printf("Enter the number vertices in graph: ");
    scanf("%d",&n);
    int A[n][n];

    printf("Enter the adjacency matrix: \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
   printf("Adj. matrix is: \n");
   print(n,A);
    warshall(n,A);
   
    
}