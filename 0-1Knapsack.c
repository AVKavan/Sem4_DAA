#include<stdio.h>

int max(int a,int b)
{   printf("%d -a and %d-b \n",a,b);
    if(a>b)
    return a;
    else return b;
}

void knap(int* weight,int* value,int cap,int n)
{        int c=cap;
    int items[n];
         int table[n+1][c+1];
         
         for(int i=0;i<=n;i++)
         table[i][0]=0;
         for(int j=0;j<=c;j++)
         table[0][j]=0;

         for(int i=1;i<=n;i++)
         {

            for(int j=1;j<=c;j++)
            {
                if(j<weight[i])
                table[i][j]=table[i-1][j];
                else
                {
                   table[i][j]=max(table[i-1][j],value[i]+table[i-1][j-weight[i]]);
                }
            }
         }

         for(int i=0;i<=n;i++)
         {

            for(int j=0;j<=c;j++)
                printf("%d\t",table[i][j]);
            
            printf("\n");
         }
         
         for(int i=n;i>=1 && c!=0;i--)
         {
            if(table[i][c]!=table[i-1][c])
            {
                items[i]=1;
                c=c-weight[i];
            }
           
         }
          printf("The max profit is %d \n",table[n][cap]);
          printf("And  the items included are: ");
         for(int i=1;i<=n;i++)
          {  if(items[i]==1)
            printf("%d\t",i);
         }
}




void main()
{   
    int n,capacity;
    printf("Enter the no of items present: ");
    scanf("%d",&n);
    int weight[n+1],value[n+1];

    printf("Enter  weights and its corresponding values:\n");
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&weight[i]);
        scanf("%d",&value[i]);
    }
   
    printf("Enter the max capacity: ");
    scanf("%d",&capacity);

    knap(weight,value,capacity,n);
}