#include "sort.h"
#include <stdio.h>

void merge_sort(edge edgelist[],int beg, int end)
{
    int mid;
    if (beg < end)
    {
        mid = (beg + end) / 2;
        merge_sort(edgelist,beg, mid);
        merge_sort(edgelist,mid + 1, end);
        merge(edgelist,beg, mid, end);   
    }
}
void merge(edge edgelist[],int beg, int mid, int end){
    int i = beg, j = mid+1;
    edge temp[(end-beg) + 1];
    int index = 0;

    while (i <= mid && j <= end)
    {
        if(edgelist[i].weight <= edgelist[j].weight)
            temp[index++] = edgelist[i++];
        else
            temp[index++] = edgelist[j++];
    }
    
    while(i <= mid)
        temp[index++] = edgelist[i++];

    while(j <= end)
        temp[index++] = edgelist[j++];
    
    // copying in main array
    for(int k = 0; k < index; k++)
        edgelist[k+beg] = temp[k];

}