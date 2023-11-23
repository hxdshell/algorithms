#include <stdio.h>

int a[] = {39, 9, 81, 45, 90, 27, 72, 18,3};
int n = sizeof(a) / sizeof(a[0]);

void merge_sort(int beg, int end);
void merge(int beg, int mid, int end);

int main(int argc, char const *argv[])
{
    merge_sort(0, n - 1);
    return 0;
}
void merge_sort(int beg, int end)
{
    int mid;
    if (beg < end)
    {
        mid = (beg + end) / 2;
        merge_sort(beg, mid);
        merge_sort(mid + 1, end);
        merge(beg, mid, end);
    }
}
void merge(int beg, int mid, int end){
    int i = beg, j = mid+1;
    int temp[(end-beg) + 1];
    int index = 0;

    while (i <= mid && j <= end)
    {
        if(a[i] <= a[j])
            temp[index++] = a[i++];
        else
            temp[index++] = a[j++];
    }
    
    while(i <= mid)
        temp[index++] = a[i++];
    while(j <= end)
        temp[index++] = a[j++];
    
    // copying in main array
    printf(">  ");
    for(int k = 0; k < index; k++){
        // also tracing
        printf("%d,",temp[k]);
        a[k+beg] = temp[k];
    }
    printf("\n");
}