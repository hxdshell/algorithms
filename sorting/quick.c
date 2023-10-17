#include <stdio.h>

int a[] = {13,7,42,26,9,18,45,2};
int n = sizeof(a)/sizeof(a[0]);

void quick_sort(int low, int high);
int partition(int low, int high);
void swap(int i, int j);

int main(int argc, char const *argv[])
{
    
    quick_sort(0,n-1);
    printf("Sorted List:\n");
    for (int i = 0; i < n; i++)
        printf("%d,",a[i]);
    printf("\n");
    return 0;
}
void quick_sort(int low, int high){
    int m;
    if(low < high){    
        m = partition(low,high);
        quick_sort(low,m-1);
        quick_sort(m+1,high);
    }
}
int partition(int low, int high){
    int i = low, j = high, pivot = a[low];
    while (i < j)
    {
        // Find larger elment than pivot
        while(pivot >= a[i] && i <= j)
            i++;

        // Find Smaller element than pivot
        while(pivot < a[j])
            j--;
        // If i is smaller than j that means there's an a[i] which is larger than a[j] so swap them.
        if(i < j)
            swap(i,j);
    }
    // j will surpass i and we will find pivot's correct position so put it there.
    swap(low,j);
    
    //-------------Tracing------------------------------------: 
    for(int k = low; k <= high; k++)
        printf("%d,",a[k]);
    printf("\n");
    printf("%d was placed in its correct position.\n\n",a[j]);
    //---------------------------------------------------------

    return j;
}
void swap(int i, int j){
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}   
