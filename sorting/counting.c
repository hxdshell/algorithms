#include <stdio.h>

void counting_sort(int a[],int sorted[], int n, int k);
int max(int a[], int n);

int main(int argc, char const *argv[])
{
    int a[] = {6, 0, 2, 0, 1, 3, 4, 6, 1, 3, 2};
    int n = sizeof(a)/sizeof(a[0]);
    int k = max(a,n);
    int sorted[n];

    counting_sort(a,sorted,n,k);
    for (int i = 0; i < n; i++)
    {
        printf("%d,",sorted[i]);
    }
    
    return 0;
}
void counting_sort(int a[],int sorted[],int n,int k){
    int count[k+1];
    
    // fill count with 0s
    for (int i = 0; i <= k; i++)
        count[i] = 0;  

    // compute histogram
    for (int i = 0; i < n; i++)
        count[a[i]] = count[a[i]] + 1;
    
    // compute prefix sum
    for (int i = 1; i <= k; i++)
        count[i] = count[i-1] + count[i];
    
    // place the value in its position given by count
    for (int i = n-1; i >= 0; i--)
    {
        count[a[i]] = count[a[i]] - 1;
        sorted[count[a[i]]] = a[i];
    }
    
}
int max(int a[],int n){
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if(a[i] > max)
            max = a[i];
    }
    return max;
}
