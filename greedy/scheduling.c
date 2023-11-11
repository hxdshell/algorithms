// Job Scheduling Problem
#include <stdio.h>
typedef struct job
{
    int id;
    int profit;
    int deadline;
}job;

int max(job jobs[], int n);
void sort(job a[], int n);
void schedule_jobs(job jobs[], int n);

int main(int argc, char const *argv[])
{
    job jobs[] = {{1,20,1},{2,15,3},{3,10,3},{4,30,2},{5,35,2}};
    int n = sizeof(jobs)/sizeof(job);

    schedule_jobs(jobs,n);

    return 0;
}
void schedule_jobs(job jobs[], int n){
    int max_deadline = max(jobs,n);
    int list[max_deadline+1];
    int profit = 0;

    for(int i = 0; i <= max_deadline; i++)
        list[i] = 0;
    
    sort(jobs,n);
    
    for(int i = 0; i < n; i++){
        if(list[jobs[i].deadline] == 0){
            list[jobs[i].deadline] = jobs[i].id;
            profit += jobs[i].profit;
        }else{
            for(int j = 1; j <= jobs[i].deadline; j++){
                if(list[j] == 0){
                    list[j] = jobs[i].id;
                    profit += jobs[i].profit;
                }
            }
        }
    }

    printf("Jobs: ");
    for(int i = 1; i <= max_deadline; i++)
        printf("%d,",list[i]);
    printf("\n");
    printf("Profit : %d\n",profit);
}
int max(job jobs[], int n){
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if(jobs[i].deadline > max){
            max = jobs[i].deadline;
        }
    }
    return max;
}
void sort(job a[], int n){
    int gap;
    int pos;
    job temp;

    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            pos = i;
            temp = a[i];
            while (a[pos - gap].profit < temp.profit && pos >= gap)
            {
                a[pos] = a[pos - gap];
                pos -= gap;
            }
            a[pos] = temp;
        }
    }
}
