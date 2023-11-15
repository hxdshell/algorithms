#ifndef HEAP_H
#define HEAP_H

typedef struct character
{
    char c;
    int frequency;
    struct character *left;
    struct character *right;
}character;

void fix_heap(character *text[], int current, int child, int last);
void heapify(character *text[], int last);
character *heap_remove(character *text[],int *last);
void heap_insert(character *text[],character *x,int *last);
void swap(character *text[], int i, int j);

#endif 
