#ifndef SORT_H
#define SORT_H

typedef struct edge
{
    int a;
    int b;
    int weight;
}edge;

void merge_sort(edge edgelist[],int beg, int end);
void merge(edge edgelist[],int beg, int mid, int end);

#endif 