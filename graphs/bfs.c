// !!! I am not gonna use adjacency list but you should use it to reduce the running time. I'll just use matrix for quick implementation. Maybe I'll change it later !!!

#include <stdio.h>
#define N 8

enum color{WHITE,GRAY,BLACK};
//white = not visited,black = visited, gray = discovered

int parent[N];
int state[N];
int discovery_time[N];

void bfs(int graph[N][N], int node);
int main(int argc, char const *argv[])
{
    int graph[N][N] = {
        {0,1,0,0,1,0,0,0},
        {1,0,0,0,0,1,0,0},
        {0,0,0,1,0,1,1,0},
        {0,0,1,0,0,0,1,1},
        {1,0,0,0,0,0,0,0},
        {0,1,1,0,0,0,1,0},
        {0,0,1,1,0,1,0,1},
        {0,0,0,1,0,0,1,0}
    };

    bfs(graph,1);

    printf("Parent:\n");
    for(int i = 0; i <N; i++)
        printf("%d,",parent[i]);
    printf("\n");

    printf("Discovery Time:\n");
    //also shortest path distance from "node";
    for(int i = 0; i < N; i++)
        printf("%d,",discovery_time[i]);
    printf("\n");
    return 0;
}
void bfs(int graph[N][N], int node){
    int queue[N];
    int top,rear;
    top = rear = 0;

    for(int i = 0; i < N; i++){
        parent[i] = -1;
        state[i] = WHITE;
        discovery_time[i] = -1;
    }
    state[node] = GRAY;
    discovery_time[node] = 0;
    queue[rear++] = node;
    
    int u;
    while(top != rear){
        u = queue[top++];
        printf("%d->",u);
        for(int v = 0; v < N; v++){
            if(graph[u][v] == 1 && state[v] == WHITE){
                queue[rear++] = v;
                parent[v] = u;
                discovery_time[v] = discovery_time[u] + 1;
                state[v] = GRAY;
            }
        }
        state[u] = BLACK;
    }
}
