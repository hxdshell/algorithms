#include <stdio.h>
#include "heap.h"

void fix_heap(character *text[], int current, int child, int last)
{
    while (child <= last)
    {
        
        if (child + 1 <= last)
            child = (text[child]->frequency < text[child + 1]->frequency) ? child : child + 1;

        if (text[child]->frequency < text[current]->frequency){
            swap(text, child, current);
        }

        current = child;
        child = (2 * child) + 1;
    }
}

void heapify(character *text[], int last)
{
    // left child : 2i + 1
    // right child : 2i + 2
    // parent : (i-1)/2
    
    int child, current;
    for (int i = last; i >= 0; i--)
    {
        child = (2 * i) + 1;
        current = i;
        fix_heap(text, current, child, last);
    }
}
character *heap_remove(character *text[],int *last){
    character *min = text[0];
    swap(text,0,*last);
    fix_heap(text,0,1,--(*last));

    return min;
}
void heap_insert(character *text[],character *x,int *last){
    text[++(*last)] = x;
    
    int current,parent;
    current = *last;
    while(current > 0){
        parent = (*last - 1)/2;

        if(text[current]->frequency < text[parent]->frequency){
            swap(text,current,parent);
            current = parent;
        }else{
            break;
        }
    }
    
}
void swap(character *text[], int i, int j)
{
    character *temp;
    temp = text[i];
    text[i] = text[j];
    text[j] = temp;
}