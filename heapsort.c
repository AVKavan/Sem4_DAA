 #include<stdio.h>
 #include<time.h>
int h[50];

void heapify(int h[],int n)
{
   int i,k,j,v,heap;
   for(int i=n/2;i>=1;i--)
   {
      k=i;
      v=h[k];
      heap=0;
      while(!(heap) && 2*k<=n)
      { 
        j=2*k;
        if(j<n)
           { if(h[j]<h[j+1])
               j++;
           }

         if(v>=h[j])
         heap=1;
         else\
           {
             h[k]=h[j];
             k=j;  
            }
          h[k]=v; 
      }
   }
}

 int main()
 {  
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);

    printf("Enter the elemnts to sort: ");
    for(int i=1;i<=n;i++)
    scanf("%d",&h[i]);

    heapify(h,n);

   int t,size;
    for(int i=n;i>=1;i--)
    {
        t=h[i];
        h[i]=h[1];
        h[1]=t;
        size=i-1;
        heapify(h,size);
   }
   
    printf("the sorted elements:\n");
    for(int i=1;i<=n;i++)
    printf("%d ",h[i]);
 }