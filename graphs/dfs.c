// !!! I am not gonna use adjacency list but you should use it to reduce the running time. I'll just use matrix for quick implementation. Maybe I'll change it later !!!
#include <stdio.h>

#define N 6

enum color{WHITE,GRAY,BLACK};
//white = not visited,black = visited, gray = discovered

typedef struct time
{
    int start;
    int end;
}time;
int global_time;

int parent[N];
int state[N];
time timings[N];

void dfs_visit(int graph[N][N],int u);
void dfs(int graph[N][N]);

int main(int argc, char const *argv[])
{
    int graph[N][N] = {
        {0,1,0,1,0,0},
        {0,0,0,0,1,0},
        {0,0,0,0,1,1},
        {0,1,0,0,0,0},
        {0,0,0,1,0,0},
        {0,0,0,0,0,1}
    };
    dfs(graph);

    printf("Discovery and Finish Time\n");
    for(int i = 0; i < N; i++)
        printf("%d/%d ",timings[i].start,timings[i].end);
    printf("\n\n");

    printf("Parents\n");
    for(int i = 0; i < N; i++)
        printf("%d,",parent[i]);

    return 0;
}
void dfs(int graph[N][N]){
    global_time = 0;
    for(int i = 0; i < N; i++){
        state[i] = WHITE;
        parent[i] = -1;
    }

    printf("Forest\n");
    for(int u = 0; u < N; u++){
        if(state[u] == WHITE){
            dfs_visit(graph,u);
            printf("\n");
        }
    }
    printf("\n");
}
void dfs_visit(int graph[N][N],int u){
    state[u] = GRAY;
    global_time++;
    timings[u].start = global_time;

    for(int v = 0; v < N; v++){
        if(graph[u][v] == 1 && state[v] == WHITE){
            parent[v] = u;
            dfs_visit(graph,v);
        }
    }
    state[u] = BLACK;
    printf("%d->",u);
    timings[u].end = ++global_time;
}
