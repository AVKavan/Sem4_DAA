#include<stdio.h>
#define INFINITY 999
int n; 
int distance[100]; 
int visited[100]; 
int cost[100][100]; 
int source;


int min_distance(){
    int min = INFINITY;
    int min_index;

    for(int i=0;i<n;i++){
        if( !visited[i] && distance[i]<=min){
            min = distance[i];
            min_index = i;
        }
    }
    return min_index;
}

void printSolution(){

    printf("Vertex and distance");
    for(int i=0;i<n;i++){
        printf("\n%d\t%d",i,distance[i]);
    }
}
void dijkstras(){

    
    for(int v=0;v<n;v++){
        distance[v] = INFINITY;
        visited[v] = 0;
    }
    
    distance[source] = 0;

    for(int i=0;i<n-1;i++){
        int min = min_distance();
        visited[min] = 1;

        for(int j=0;j<n;j++){
            if(!visited[j] && cost[min][j] && (distance[min] != INFINITY) && distance[j]>distance[min]+cost[min][j] ){
                distance[j] = distance[min] + cost[min][j];
            }
        }
    }

    printSolution();

}

void main(){

    printf("\nEnter the number of vertices:\t");
    scanf("%d",&n);
    printf("Enter the distance matrix");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
        }
    }

    printf("\nEnter the source node:\t");
    scanf("%d",&source);

    dijkstras();
}