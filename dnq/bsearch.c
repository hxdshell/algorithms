#include <stdio.h>

int binary_search(int a[], int val,int beg,int end);
int main(int argc, char const *argv[])
{
    int a[] = {10,13,23,28,34,43,57,65,71};
    int n = sizeof(a)/sizeof(a[0]);
    int index = binary_search(a,23,0,n-1);

    printf("%d\n",index);
    return 0;
}
int binary_search(int a[], int val,int beg,int end){
    int mid;

    if(beg <= end){
        mid = (beg + end) / 2;
        printf("mid : %d\n",mid);
        if(a[mid] == val){
            return mid;
        }
        else if(a[mid] < val){
            return binary_search(a,val,mid+1,end);
        }
        else{
            return binary_search(a,val,beg,mid-1);
        }
    }

    return -1;
}