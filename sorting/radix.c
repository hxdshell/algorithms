#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

#define RADIX 10

int max(int a[], int n);
void radix_sort(int a[], int n);
bool clear(node *buckets[]);

int main(int argc, char const *argv[])
{
    int a[] = {78,1,100,99,25,22};
    int n = sizeof(a) / sizeof(a[0]);

    radix_sort(a, n);
    return 0;
}

void radix_sort(int a[], int n)
{
    int largest = max(a, n);
    int k = 1, key, index;
    node *new_node = NULL, *top;

    node *buckets[RADIX];

    for (int i = 0; i < RADIX; i++)
    {
        buckets[i] = NULL;
    }
    while (k <= largest)
    {
        // place items in respective buckets based on the digit
        for (int i = 0; i < n; i++)
        {
            key = (a[i] / k) % 10;
            new_node = malloc(sizeof(node));
            new_node->data = a[i];
            new_node->next = NULL;

            if (buckets[key] == NULL)
            {
                buckets[key] = new_node;
            }
            else
            {
                top = buckets[key];
                while (top->next != NULL)
                {
                    top = top->next;
                }
                top->next = new_node;
            }
        }
        // get partially sorted array
        index = 0;
        for (int i = 0; i < RADIX; i++)
        {
            if (buckets[i] != NULL)
            {
                top = buckets[i];
                while (top != NULL)
                {
                    a[index] = top->data;
                    index++;
                    top = top->next;
                }
            }
        }
        // The element is placed on its right place
        // below loop is to print and analyze all the passes and is not part of the algorithm
        printf(">  ");
        for (int k = 0; k < n; k++)
        {
            printf("%d ", a[k]);
        }
        printf("\n");
        //------------------------------------------------------------------------

        k *= 10;
        if (!clear(buckets))
        {
            printf("Error: could not clear the bucket\n");
            return;
        }
    }
}

int max(int a[], int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}
bool clear(node *buckets[])
{
    node *cursor = NULL;
    node *tmp = NULL;

    for (int i = 0; i < RADIX; i++)
    {
        if (buckets[i] != NULL)
        {
            cursor = buckets[i];
            while (cursor != NULL)
            {
                tmp = cursor;
                cursor = cursor->next;
                free(tmp);
            }
            buckets[i] = NULL;
        }
    }
    return true;
}
