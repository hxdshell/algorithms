#include <stdio.h>
#include <string.h>

enum direction{CROSS,TOP,LEFT};

int lcs(char *x, char *y);
void backtrack(int r, int c, int direct[r][c], int length);
char *x = "abcbdab", *y = "bdcaba";

int main(int argc, char const *argv[])
{
    int length = lcs(x,y);
    printf("Length: %d\n",length);
    return 0;
}
int lcs(char *x, char *y){
    int n = strlen(x), m = strlen(y);

    int table[n+1][m+1];
    int direct[n+1][m+1];
    // init
    for(int i = 0; i <= n; i++){

        table[i][0] = 0;
    }
    for(int i = 0; i <= m; i++){
        table[0][i] = 0;
    }

    
    for (int i = 1; i <= n ; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // printf("%c & %c -> ",x[i-1],y[j-1]);
            if(x[i-1] == y[j-1]){
                table[i][j] = table[i-1][j-1] + 1;
                direct[i][j] = CROSS;
            }else{
                if(table[i-1][j] >= table[i][j-1]){
                    table[i][j] = table[i-1][j];
                    direct[i][j] = TOP;
                }else{
                    table[i][j] = table[i][j-1];
                    direct[i][j] = LEFT;
                }
            }
            printf("%d , ",table[i][j]);
        }
        printf("\n");
    }
    backtrack(n+1,m+1,direct,table[n][m]);
    return table[n][m];
}
void backtrack(int r, int c, int direct[r][c], int length){
    char lcs[length];
    int index = length-1;
    int row = r-1, col = c-1;
    
    while (row >0 && col > 0){
        if(direct[row][col] == CROSS){
            lcs[index--] = x[row-1];
            row--;
            col--;
        }else if(direct[row][col] == TOP){
            row--;
        }else{
            col--;
        }
    }
    for (int i = 0; i < length; i++)
    {
        printf("%c",lcs[i]);
    }
    printf("\n");
}
