#include <stdio.h>

void matrix_chain_ordering(int d[], int n);
void optimal_ordering(int total,int s[total][total],int i, int j);

int main(int argc, char const *argv[])
{
    int d[] = {30,35,15,5,10,20,25};
    int n = sizeof(d)/sizeof(d[0]);
    matrix_chain_ordering(d,n);
}
void matrix_chain_ordering(int d[], int n){
    int total = n-1;
    int m[total][total];
    int s[total][total];

    //intit
    for(int i = 0; i < total; i++){
        for(int j = 0; j <= i; j++){
            m[i][j] = 0;
            s[i][j] = -1;
        }
    }
    
    // Calculation
    int len,i,j,k;
    int cost;
    for(len = 1; len < total; len++){
        for(i = 0; i < total-len; i++){
            j = len + i;  //or j = total - i + 1
            m[i][j] = __INT32_MAX__;
            for(k = i; k < j; k++){
                cost = m[i][k] + m[k+1][j] + (d[i]*d[k+1]*d[j+1]);
                if(cost < m[i][j]){
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
    printf("Optimal Order with the cost of %d:\n",m[0][total-1]);
    optimal_ordering(total,s,0,n-2);
}
void optimal_ordering(int total,int s[total][total],int i, int j){
    if(i == j)
        printf(" A%d ",i+1);
    else{
        printf("(");
        optimal_ordering(total,s,i,s[i][j]);
        optimal_ordering(total,s,s[i][j]+1,j);
        printf(")");
    }
}