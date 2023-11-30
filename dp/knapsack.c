#include <stdio.h>

int knapsack(int v[], int w[], int n ,int max_weight);
void trace_knapsack(int v[], int w[],int n, int max_weight, int table[n+1][max_weight+1]);
int main(int argc, char const *argv[])
{
    int v[] = {25,20,15,40,50};
    int w[] = {3,2,1,4,5};
    int value = knapsack(v,w,5,6);
    printf("%d\n",value);
    return 0;
}
int knapsack(int v[], int w[], int n ,int max_weight){
    int table[n+1][max_weight+1];

    for(int i = 0; i <= n; i++)
        table[i][0] = 0;

    for(int i = 0; i <= max_weight; i++)
        table[0][i] = 0;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= max_weight; j++)
        {
            if(w[i-1] <= j){
                table[i][j] = (table[i-1][j] > (table[i-1][j - w[i-1]] + v[i-1])) ? table[i-1][j] : (table[i-1][j-w[i-1]] + v[i-1]);
            }
            else{
                table[i][j] = table[i-1][j];
            }
        }
        
    }
    for (int i = 1; i <= n ; i++)
    {
        for (int j = 1; j <= max_weight; j++)
        {
            printf("%d ",table[i][j]);
        }
        printf("\n");
    }
    
    
    trace_knapsack(v,w,n,max_weight,table);
    return table[n][max_weight];
}
void trace_knapsack(int v[], int w[],int n, int max_weight, int table[n+1][max_weight+1]){
    int i = n, j = max_weight;
    while( j > 0){
        if(table[i][j] == table[i-1][j]){
            i--;
        }else{
            j = j- w[i-1];
            printf("Value : %d Weight: %d\n",v[i-1],w[i-1]);
        }
    }
}