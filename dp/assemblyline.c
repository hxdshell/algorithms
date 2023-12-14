#include <stdio.h>

#define LINES 2
#define STATIONS 6

int assembly_line_scheduling(int stationCost[LINES][STATIONS],int transitionCost[LINES][STATIONS-1],int entryExitCost[LINES][2]);

int main(int argc, char const *argv[])
{
    int stationCost[LINES][STATIONS] = {
        {7,9,3,4,8,4},
        {8,5,6,4,5,7}
    };
    int transitionCost[LINES][STATIONS-1] = {
        {2,3,1,3,4},
        {2,1,2,2,1}
    }; 
    int entryExitCost[LINES][2] = {
        {2,3},
        {4,2}
    };

    assembly_line_scheduling(stationCost,transitionCost,entryExitCost);
    return 0;
}
int assembly_line_scheduling(int stationCost[LINES][STATIONS],int transitionCost[LINES][STATIONS-1],int entryExitCost[LINES][2]){
    
    int costTable[LINES][STATIONS],trackTable[LINES][STATIONS];
    int optimalSequence[STATIONS];

    int finalCost,exitLine;
    int normal,transit;

    // inint
    costTable[0][0] = stationCost[0][0] + entryExitCost[0][0];
    costTable[1][0] = stationCost[1][0] + entryExitCost[1][0];

    trackTable[0][0] = 0;
    trackTable[1][0] = 1;

    // Calculation
    for(int i = 1; i < STATIONS; i++){
        for(int j = 0; j < LINES; j++){
            normal = costTable[j][i-1] + stationCost[j][i];
            transit = stationCost[j][i] + costTable[(j+1)%2][i-1] + transitionCost[(j+1)%2][i-1];

            if(normal < transit){
                costTable[j][i] = normal;
                trackTable[j][i] = j;
            }else{
                costTable[j][i] = transit;
                trackTable[j][i] = (j+1) % 2;
            }
        }
    }
    // Exit calculation
    int cost1,cost2;
    cost1 = costTable[0][STATIONS-1] + entryExitCost[0][1];
    cost2 = costTable[1][STATIONS-1] + entryExitCost[1][1];

    if(cost1 < cost2){
        finalCost = cost1;
        exitLine = 0;
    }else{
        finalCost = cost2;
        exitLine = 1;
    }

    optimalSequence[STATIONS-1] = exitLine;
    for(int i = STATIONS-2; i >= 0; i--)
        optimalSequence[i] = trackTable[optimalSequence[i+1]][i+1];

    //Result
    printf("Optimal Sequence with the cost of %d\n",finalCost);
    for(int i = 0; i < STATIONS; i++)
        printf("%d,",optimalSequence[i]);
    printf("\n");
    return 0;
}
