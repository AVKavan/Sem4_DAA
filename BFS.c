 #include<stdio.h>
 #include<stdlib.h>

typedef struct queue
{
    int size;
    int f;
    int r;
    int* arr;
}queue;

int IsEmpty(queue* q)
{
    if(q->f==q->r)
    return 1;

    return 0;
}




void enqueue(queue* q,int val)
{
    q->arr[++q->r]=val;
}

int dequeue(queue* q)
{
    return q->arr[++q->f];
}




 int main()
 {  int n,initial;
    printf("Enter the numebr of the nodes: ");
    scanf("%d",&n);
    
    queue q;
    q.size=n;
    q.f=q.r=-1;
    q.arr=(int*)malloc(q.size*sizeof(int));
    int a[n][n];

    printf("Enter the adjacency matrix: \n");
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    scanf("%d",&a[i][j]);

    printf("Enter the initial node: ");
    scanf("%d",&initial);

    int visited[100]={0};

    visited[initial]=1;
    enqueue(&q,initial);
    
    printf("%d",initial);
    while(!IsEmpty(&q))
    {    
            int node= dequeue(&q);

            for(int j=0;j<n;j++)
            {
                if(!visited[j] && a[node][j])
                {
                    printf("->%d",j);
                    visited[j]=1;
                    enqueue(&q,j);
                }
            }
    }





 }