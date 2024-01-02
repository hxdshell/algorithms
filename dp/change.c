#include <stdio.h>

int a[3] = {2,5,7};
int n = sizeof(a)/sizeof(a[0]);

int change(int amount);
void which_coins(int r, int c,int table[r][c]);

int main(int argc, char const *argv[])
{
    int amount = 12; 
    int coins = change(amount);
    printf("no. of coins : %d\n",coins);
    return 0;
}
int change(int amount){
    int table[n][amount+1];
    
    // init
    for(int i = 0; i < n; i++)
        table[i][0] = 0;
    
    // calc for first denomination
    for (int i = 1; i <= amount; i++)
    {
        if(a[0] <= i)
            table[0][i] = table[0][i-a[0]] + 1;
    }
    // remaining denominations
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            table[i][j] = (table[i-1][j] < (table[i][j-a[i]] + 1)) ? table[i-1][j] : (table[i][j-a[i]] + 1);
        }
    }
    
    which_coins(n,amount+1,table);
    return table[n-1][amount];
}
void which_coins(int r, int c,int table[r][c]){
    int row = r-1, col = c-1;
    int no[n];
    for(int i = 0; i < n ; i++)
        no[i] = 0;
    
    while (row >= 0)
    {
        if(table[row][col] == (table[row][col - a[row]] + 1)){
            no[row]++;
            col = col - a[row];
        }else{
            row--;
        }
    }
    
    for(int i = 0; i < n ; i++)
        printf("%d :: %d\n",a[i],no[i]);
    
}