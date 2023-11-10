// Fractional Knapsack

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 5
#define W 100

void knapsack(int w[], int v[]);
void sort(double vpw[], int v[], int w[]);
int main(int argc, char const *argv[])
{
    int weights[] = {10, 20, 30, 40, 50};
    int values[] = {20, 30, 66, 40, 60};

    knapsack(weights, values);
    return 0;
}
void knapsack(int w[], int v[])
{
    double vpw[N];
    double x[N] = {0};

    int weight = 0, value = 0;

    // Calculate value per weight
    for (int i = 0; i < N; i++)
        vpw[i] = v[i] / (double)w[i];

    sort(vpw,v,w);
    
    for(int i = 0; weight < W; i++){
        if((weight + w[i]) <= W){
            weight += w[i];
            value += v[i];
            x[i] = 1;
        }else{
            x[i] = (W - weight)/ (double)w[i];
            weight += x[i] * w[i];
            value += x[i] * v[i];
        }
    }

    // Output 
    printf("x = { ");
    for(int i = 0; i < N; i++)
        printf("%.2lf, ",x[i]);
    printf("}\n");

    printf("Value : %d\n",value);
}
void sort(double vpw[], int v[], int w[]){
    int flag;
    double temp;
    for (int i = 0; i < N; i++)
    {
        flag = 0;
        for (int  j = 0; j < (N - i)-1; j++)
        {
            if(vpw[j] < vpw[j+1]){
                temp = vpw[j];
                vpw[j] = vpw[j+1];
                vpw[j+1] = temp;

                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;

                temp = w[j];
                w[j] = w[j+1];
                w[j+1] = temp;

                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }
}
