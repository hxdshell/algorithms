#include <stdio.h>

void selection_sort(int a[],int n);
int main(int argc, char const *argv[])
{
    int a[] = {98,54,86,9,92,43,71};
    int n = sizeof(a)/sizeof(a[0]);

    selection_sort(a,n);
    printf("\n\n");
    selection_sort(a,n);
    
    return 0;
}

void selection_sort(int a[],int n){
    
    int small,pos,temp;
    for (int i = 0; i < n-1; i++)
    {
        small = a[i];
        pos = i;
        for (int j = i+1; j < n; j++)
        {
            if(a[j] < small){
                small = a[j];
                pos = j;
            }
        }
        a[pos] = a[i];
        a[i] = small;

        // The element is placed on its right place
        // below loop is to print and analyze all the passes and is not part of the algorithm

        printf("Pass %d : ",i+1);
        for (int k = 0; k < n; k++)
        {
            printf("%d ",a[k]);    
        }
        printf("\n");
    }
    
}