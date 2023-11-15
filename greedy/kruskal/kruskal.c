#include <stdio.h>
#include "sort.h"

void kruskal(edge edgelist[],int n, char nodelist[],int nodes);
char find(char parent[],char x);
void set_union(char parent[], int rank[], char x, char y);

int main(int argc, char const *argv[])
{
    edge edgelist[] = {{'A','B',3},{'A','C',6},{'B','C',2},{'B','D',4},{'C','D',1},{'C','E',4},{'C','F',2},{'D','E',2},{'D','G',4},{'E','F',2},{'E','G',1},{'F','G',1}};
    int n = sizeof(edgelist)/sizeof(edge);
    char nodelist[] = {'A','B','C','D','E','F','G'};
    int nodes = sizeof(nodelist)/sizeof(char);
    kruskal(edgelist,n,nodelist,nodes);
    return 0;
}
void kruskal(edge edgelist[],int n, char nodelist[],int nodes){
    char parent[nodes];
    int rank[nodes];

    // Make set
    for(int i = 0; i < nodes; i++){
        parent[i] = nodelist[i];
        rank[i] = 0;
    }

    // Sort
    merge_sort(edgelist,0,n-1);

    // Find Edges for MST
    edge mst_edges[nodes-1];
    int index = 0;
    int cost = 0;

    printf("Edges of MST:\n");
    for(int i = 0; i < n; i++){
        if(find(parent,edgelist[i].a) != find(parent,edgelist[i].b)){
            mst_edges[index++] = edgelist[i];
            printf("%c -> %c : %d\n",edgelist[i].a,edgelist[i].b,edgelist[i].weight);
            cost += edgelist[i].weight;
            set_union(parent,rank,edgelist[i].a,edgelist[i].b);
        }
    }
    printf("\nCost = %d\n",cost);
}
char find(char parent[],char x){
    int index = (int)x - 65;
    if(parent[index] != x)
        parent[index] = find(parent,parent[index]);
    
    return parent[index];
}

void set_union(char parent[], int rank[], char x, char y){
    x = find(parent,x);
    y = find(parent,y);

    int xindex = (int)x - 65;
    int yindex = (int)y - 65;

    if(rank[xindex] > rank[yindex]){
        parent[yindex] = x;
    }else if(rank[xindex] < rank[yindex]){
        parent[xindex] = y;
    }else{
        parent[yindex] = x;
        rank[xindex]++; 
    }
}
