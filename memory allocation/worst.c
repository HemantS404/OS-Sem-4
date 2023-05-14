#include <stdio.h>

struct process{
    int required, isAllocated;
};
struct process pro[10];

struct memory{
    int space, isFilled, hole, pID;
};
struct memory mem[10];

int getWorstFitMem(int processID, int noMemory){
    int worstFit = -1;
    for(int i=0; i<noMemory; i++){
        if(mem[i].isFilled != 1 && mem[i].space >= pro[processID].required){
            worstFit = i;
            break;
        }
    }
    if (worstFit != -1){
        for(int i=worstFit; i<noMemory; i++){
            if(mem[i].isFilled != 1 && mem[i].space >= pro[processID].required && mem[i].space > mem[worstFit].space){
                worstFit = i;
            }
        }
    }
    return worstFit;
}

void main(){
    int noMemory, noProcess;
    printf("Enter total number of process : ");
    scanf("%d", &noProcess);
    printf("Enter total number of memory : ");
    scanf("%d", &noMemory);
    printf("\nEnter Process memory required\n");
    for (int i=0; i<noProcess; i++){
        printf("Enter P%d required memory : ", i+1);
        scanf("%d", &pro[i].required);
        pro[i].isAllocated = 0;
    }
    printf("\nEnter Memory space\n");
    for (int i=0; i<noMemory; i++){
        printf("Enter M%d memory space : ", i+1);
        scanf("%d", &mem[i].space);
        mem[i].isFilled = 0;
    }
    for (int i=0; i<noProcess; i++){
        int worstFit = getWorstFitMem(i, noMemory);
        if (worstFit != -1){
            mem[worstFit].isFilled = 1;
            pro[i].isAllocated = 1;
            mem[worstFit].hole = mem[worstFit].space - pro[i].required;
            mem[worstFit].pID = i+1;
        }
    }
    printf("\n");
    for (int i=0; i<noMemory; i++){
        if(mem[i].isFilled == 1){
            printf("MID : %d, PID : %d, Hole : %d\n", i+1, mem[i].pID, mem[i].hole);
        }
    }
    printf("\n");
    for (int i=0; i<noProcess; i++){
        if(pro[i].isAllocated != 1){
            printf("P%d is not allocated\n", i+1);
        }
    }
}