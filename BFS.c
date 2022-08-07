#include<stdio.h>
#include<stdlib.h>
 
struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};
 
 
int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
 
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
 
void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        ;
    }
}
 
int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f]; 
    }
    return a;
}
 
int main(){
    int n,i;
    struct queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size*sizeof(int));
    printf("Enter the number of nodes: ");
    scanf("%d",&n);

    int a[n][n];
    printf("Enter the adjacency matrix:\n");
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    scanf("%d",&a[i][j]);

    printf("Enter the start node ,Note: initial node starts from 0 and not 1\n");
    scanf("%d",&i);
     
    int node;
    int visited[n];
    for(int j=0;j<n;j++)
    visited[j]=0;

    printf("%d", i);
    visited[i] = 1;
    enqueue(&q, i); 
    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if(a[node][j] ==1 && visited[j] == 0){
                printf("->%d", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
    return 0;
}