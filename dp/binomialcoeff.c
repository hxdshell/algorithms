#include <stdio.h>

int binomial_coefficient(int n, int k);
int main(int argc, char const *argv[])
{
    int n,k;
    printf("Enter n and k: ");
    scanf("%d%d",&n,&k);
    int nCk = binomial_coefficient(n,k);
    printf("%dC%d = %d\n",n,k,nCk);
    return 0;
}
int binomial_coefficient(int n, int k){
    // Pascal's Traiangle 

    int table[n+1][k+1];
    
    for(int i = 0; i <= n; i++)
        table[i][0] = 1;
    for(int i = 1; i <= k; i++)
        table[0][i] = 0;
    
    int i,j;
    for(i = 1; i <= n; i++){
        for(j = 1; (j <= i && j <= k); j++){
            table[i][j] = table[i-1][j-1] + table[i-1][j];
        }
        while(j <= k){
            table[i][j] = 0;
            j++;
        }
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; (j <= i && j <= k); j++){
            printf("%d ",table[i][j]);
        }
        printf("\n");
    }
    return table[n][k];
}