#include <stdio.h>

void bubble_sort(int a[],int n);
int main(int argc, char const *argv[])
{
    int a[] = {98,92,86,71,54,43,9};
    int n = sizeof(a)/sizeof(a[0]);

    bubble_sort(a,n);
    printf("\n\n");
    bubble_sort(a,n);
    
    return 0;
}
void bubble_sort(int a[],int n){
    int temp,flag;
    for (int i = 0; i < n; i++)
    {
        flag = 0;
        for (int j = 0; j < (n-i)-1; j++)
        {
            if (a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = 1;
            }
            
        }
        if(flag == 0){
            break;
        }
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