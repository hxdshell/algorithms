#include <stdio.h>
#include <stdbool.h>
#define N 7

void prim(int rows,int columns,int graph[rows][columns]);
int find_min(int key[], bool selected[]);

int main(int argc, char const *argv[])
{
    int graph[7][7] = {
        {0,3,6,0,0,0,0},
        {3,0,2,4,0,0,0},
        {6,2,0,1,4,2,0},
        {0,4,1,0,2,0,4},
        {0,0,4,2,0,2,1},
        {0,0,2,0,2,0,1},
        {0,0,0,4,1,1,0}
    };
    prim(N,N,graph);
    return 0;
}
void prim(int rows,int columns,int graph[rows][columns]){
    int key[N],parent[N];
    bool selected[N];

    // init
    for(int i = 0; i < N; i++){
        key[i] = __INT32_MAX__;
        parent[i] = -1;
    }
    int edges = 0;
    int min;

    key[0] = 0;

    while(edges < N-1){
        min = find_min(key,selected);
        selected[min] = true;

        for(int i = 0; i < N; i++){
            if(graph[min][i] && !selected[i] && graph[min][i] < key[i]){
                key[i] = graph[min][i];
                parent[i] = min;
            }
        }
        edges++;
    }

    int cost = 0;
    printf("Cost of Edges:\n");
    for(int i = 0; i < N; i++){
        cost += key[i];
        printf("%d,",key[i]);
    }
    
    printf("\nCost of MST: %d\n",cost);
}
int find_min(int key[],bool selected[]){
    int min = __INT32_MAX__;
    int pos;
    for(int i = 0; i < N; i++){
        if(key[i] < min && !selected[i]){
            min = key[i];
            pos = i;
        }
    }
    return pos;
}
