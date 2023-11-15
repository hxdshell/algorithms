#include <stdio.h>
#include <stdbool.h>

#define N 5

void dijkstra(int digraph[N][N], int source);
int findmin(int distance[], bool visited[]);

int main(int argc, char const *argv[])
{
    int digraph[N][N] = {
        {0,10,3,20,0},
        {0,0,0,5,0},
        {0,2,0,0,15},
        {0,0,0,0,11},
        {0,0,0,0,0}
    };
    dijkstra(digraph,0);
    return 0;
}
void dijkstra(int digraph[N][N], int source){
    int distance[N];
    distance[source] = 0;
    bool visited[N];

    // Init
    for(int i = 0; i < N; i++){
        if(i == source)
            continue;

        distance[i] = __INT32_MAX__;
    }

    //Relax
    int nodes = 0,min,newcost;
    while(nodes < N){
        min = findmin(distance,visited);
        visited[min] = true;
        nodes++;

        for(int i = 0; i < N; i++){
            if(digraph[min][i] && !visited[i]){
                newcost = distance[min] + digraph[min][i];
                if(newcost < distance[i])
                    distance[i] = newcost;
            }
        }
    }
    printf("Traversing cost from %d\n",source);
    for(int i = 0; i < N; i++)
        printf("%d => %d\n",i,distance[i]);
}
int findmin(int distance[], bool visited[]){
    int min = __INT32_MAX__,pos;
    for(int i = 0; i < N; i++){
        if(!visited[i] && distance[i] < min){
            min = distance[i];
            pos = i;
        }
    }
    return pos;
}