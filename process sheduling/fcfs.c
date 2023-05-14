#include <stdio.h>
#include <stdlib.h>

struct process{
    int arrival, burst, completion, turnaround, waiting;
};
struct process pq[10];

void main(){
    int total, clock=0;
    float avgTAT=0, avgWT=0;
    printf("This is FCFS process sheduling\n");
    printf("Enter number of processes : ");
    scanf("%d",&total);
    
    for (int i=0; i<total; i++){
        printf("Enter process arrival time, burst time : ");
        scanf("%d%d",&pq[i].arrival,&pq[i].burst);
    }
    for(int i=1; i<total; i++){
        int j = i-1;
        struct process key = pq[i];
        while(j >= 0 && key.arrival < pq[j].arrival){
            struct process temp = pq[j];
            pq[j+1] = pq[j];
            pq[j] = temp;
            j--;
        }
        pq[j+1] = key;
    }


    clock = pq[0].arrival;
    for(int i=0; i<total; i++){
        if(clock < pq[i].arrival){
            clock = pq[i].arrival;
        }
        pq[i].completion = pq[i].burst + clock;
        clock += pq[i].burst;
        pq[i].turnaround = pq[i].completion - pq[i].arrival;
        pq[i].waiting = pq[i].turnaround  - pq[i].burst;
    }

    printf("Id\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0; i<total; i++){
        avgTAT += pq[i].turnaround;
        avgWT += pq[i].waiting;
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i, pq[i].arrival, pq[i].burst, pq[i].completion, pq[i].turnaround, pq[i].waiting);
    }
    avgTAT /= total; 
    avgWT /= total; 
    printf("Avg TAT : %.2f, Avg WT : %.2f", avgTAT, avgWT);
}