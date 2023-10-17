#include <stdio.h>

void swap(int a[], int i, int j);
void heapify(int a[], int last);
void heap_sort(int a[], int n);
void fix_heap(int a[], int current, int child, int last);

int main(int argc, char const *argv[])
{
    int a[] = {5, 13, 2, 25, 7, 17, 20, 8, 4};
    int n = sizeof(a) / sizeof(a[0]);
    heap_sort(a, n);
    printf("Sorted: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d,", a[i]);
    }
    printf("\n");
    return 0;
}
void heapify(int a[], int last)
{
    // left child : 2i + 1
    // right child : 2i + 2
    // parent : (i-1)/2
    
    int child, current;
    for (int i = last; i >= 0; i--)
    {
        child = (2 * i) + 1;
        current = i;
        fix_heap(a, current, child, last);
    }
}

void heap_sort(int a[], int n)
{
    int last = n - 1;

    heapify(a, last);

    for (int i = 0; i < n; i++)
    {
        swap(a, 0, last);
        last--;
        fix_heap(a, 0, 1, last);
    }
}

void fix_heap(int a[], int current, int child, int last)
{
    while (child <= last)
    {
        if (child + 1 <= last)
            child = (a[child] > a[child + 1]) ? child : child + 1;

        if (a[child] > a[current])
            swap(a, child, current);

        current = child;
        child = (2 * child) + 1;
    }
}
void swap(int a[], int i, int j)
{
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
