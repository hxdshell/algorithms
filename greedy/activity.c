#include <stdio.h>

typedef struct activity
{
    int id;
    int s;
    int f;
}activity;

#define N 6

void sort(activity a[]);
void activity_selection(activity activities[]);

int main(int argc, char const *argv[])
{
    activity activities[N] = {{1,4,8},{2,1,6},{3,0,3},{4,3,5},{5,8,11},{6,5,8}};

    activity_selection(activities);
    return 0;
}

void activity_selection(activity activities[]){
    int k = 0;

    // sort by finish time
    sort(activities);
    
    // atleast first activity can be selected
    printf("Selected Activities :\n");
    printf("Activity %d, Start : %d Finish : %d\n",activities[0].id,activities[0].s,activities[0].f);

    for (int i = k+1; i < N; i++)
    {
        if(activities[i].s >= activities[k].f){
            k = i;
            printf("Activity %d, Start : %d Finish : %d\n",activities[i].id,activities[i].s,activities[i].f);
        }
    }
}

void sort(activity a[]){
    int gap;
    int pos;
    activity temp;

    for (gap = N / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < N; i++)
        {
            pos = i;
            temp = a[i];
            while (a[pos - gap].f > temp.f && pos >= gap)
            {
                a[pos] = a[pos - gap];
                pos -= gap;
            }
            a[pos] = temp;
        }
    }
}