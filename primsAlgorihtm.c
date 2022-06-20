
#include<stdio.h>

int cost[20][20];
int visited[20] = {0};
int min_cost = 0;
void prims(int n){

    int ne  = 1; //This is to keep track of the number of edges in MST, should be n-1;
    int a; //this is the source of the edge.
    int b; //this is the destination of the edge.

    while(ne<n){
        int min = 999;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(cost[i][j] < min){
                    //ALl following is valid only i is visited.
                    if(visited[i] != 0){
                        min = cost[i][j];
                        a = i; //source
                        b = j; //destination
                    }
                }
            }
        }

        if(visited[a] == 0 || visited[b] == 0){
            printf("\nEdge %d: from %d to %d, cost: %d",ne,a,b,min);
            min_cost += min;
            ne++;
            visited[b] = 1; //marking the destination as visited.
        }
        //Before the loop restarts marking cost[a][b] and cost[b][a] as 999
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\n----------------------------------------------------\n");
    printf("\nThe minimum spanning tree cost is %d\n",min_cost);
    printf("\n----------------------------------------------------\n");
}

void main(){

    int n;
    printf("\nEnter the number of vertices in the graph.");
    scanf("%d",&n);

    printf("\nEnter the cost of each edge of tree");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j] == 0){
                cost[i][j] = 999;
            }
        }
    }
    int source;
    printf("\nEnter the source node:\t");
    scanf("%d",&source);
    visited[source] = 1;

    prims(n);
}
