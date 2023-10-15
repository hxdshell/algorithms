#include <stdio.h>

void shell_sort(int a[], int n);
int main(int argc, char const *argv[])
{
    int a[] = {81, 23, 21, 50, 83, 33, 61, 20};
    int n = sizeof(a) / sizeof(a[0]);
    shell_sort(a, n);
    return 0;
}

void shell_sort(int a[], int n)
{
    //{81, 23, 21, 50, 83, 33, 61, 20}
    int gap;
    int pos, temp;
    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            pos = i;
            temp = a[i];
            while (a[pos - gap] > temp && pos >= gap)
            {
                a[pos] = a[pos - gap];
                pos -= gap;
            }
            a[pos] = temp;
            // The element is placed on its right place
            // below loop is to print and analyze all the passes and is not part of the algorithm

            printf("Pass %d : ", gap);
            for (int k = 0; k < n; k++)
            {
                printf("%d ", a[k]);
            }
            printf("\n");
        }
    }
}