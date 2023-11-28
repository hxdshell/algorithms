#include <stdio.h>

typedef struct minmax
{
    int min;
    int max;
}minmax;

minmax find_min_max(int a[], int beg, int end);
int main(int argc, char const *argv[])
{
    int a[] = {7,13,-2,3,14,37,32,9};
    int n = sizeof(a)/sizeof(a[0]);

    minmax min_and_max = find_min_max(a,0,n-1);
    printf("Min : %d Max : %d\n",min_and_max.min,min_and_max.max);
    return 0;
}
minmax find_min_max(int a[], int beg, int end){
    minmax min_and_max;
    int mid;

    if(beg+1 == end){
        min_and_max.min = (a[beg] <= a[end]) ? a[beg] : a[end];
        min_and_max.max = (a[beg] >= a[end]) ? a[beg] : a[end];

        return min_and_max;
    }

    mid = (beg+end)/2;

    minmax left = find_min_max(a,beg,mid);
    minmax right = find_min_max(a,mid+1,end);

    min_and_max.min = (left.min <= right.min) ? left.min : right.min;
    min_and_max.max = (left.max >= right.max) ? left.max : right.max;

    return min_and_max;
}

