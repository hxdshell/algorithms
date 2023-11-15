#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

void huffman(character a[],int n);
void generate_codes(character *root,char *code,int len);

int main(int argc, char const *argv[])
{
    character text[] = {{'a',23}, {'e',14}, {'i',11}, {'o',30}, {'u',43}, {'y',9}, {'t',5}};
    int n = sizeof(text)/sizeof(text[0]);
    huffman(text,n);   
    return 0;
}
void huffman(character a[],int n){
    character *text[n];
    int last = n-1;
    
    for(int i = 0; i < n; i++){
        text[i] = malloc(sizeof(character));

        text[i]->c = a[i].c;
        text[i]->frequency = a[i].frequency;
        text[i]->left = text[i]->right = NULL;
    }

    // Build Heap
    heapify(text,last);
    
    // Build Huffman Tree
    character *min;
    for(int i = 0; i < n-1; i++){
        min = malloc(sizeof(character));

        min->left = heap_remove(text,&last);
        min->right = heap_remove(text,&last);
        min->frequency = min->left->frequency + min->right->frequency;

        heap_insert(text,min,&last);
    }
    
    // Generate Codes
    character *top = heap_remove(text,&last);
    generate_codes(top,"",0);
}
void generate_codes(character *root,char *code,int len){
    char buffer[len+1];

    if(!root->left && !root->right){
        printf(" %c => %s\n",root->c,code);
        free(root);
    }else{
        if(root->left){
        strcpy(buffer,code);
            strcat(buffer,"0");
            generate_codes(root->left,buffer,strlen(buffer));
        }
        if(root->right){
            strcpy(buffer,code);
            strcat(buffer,"1");
            generate_codes(root->right,buffer,strlen(buffer));
        }
    }
}
