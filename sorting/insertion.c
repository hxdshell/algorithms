#include <stdio.h>

void insertion_sort(int a[], int n);
int main(int argc, char const *argv[])
{
    int a[] = {98, 54, 86, 9, 92, 43, 71};
    int n = sizeof(a) / sizeof(a[0]);
    insertion_sort(a, n);

    return 0;
}

void insertion_sort(int a[], int n)
{
    //{98,54,86,9,92,43,71}

    int pos, val;
    for (int i = 1; i < n; i++)
    {
        val = a[i];
        pos = i - 1;
        while (val <= a[pos] && pos >= 0)
        {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = val;

        // The element is placed on its right place
        // below loop is to print and analyze all the passes and is not part of the algorithm

        printf("Pass %d : ", i);
        for (int k = 0; k < n; k++)
        {
            printf("%d ", a[k]);
        }
        printf("\n");
    }
}
