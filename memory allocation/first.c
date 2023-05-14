#include <stdio.h>

struct process{
    int requied, isAllocated;
};
struct process pro[10];

struct memory{
    int space, isFilled, hole, pID;
};
struct memory mem[10];

void main(){
    int noMemory, noProcess;
    printf("Enter total number of process : ");
    scanf("%d", &noProcess);
    printf("Enter total number of memory : ");
    scanf("%d", &noMemory);
    printf("\nEnter Process memory required\n");
    for (int i=0; i<noProcess; i++){
        printf("Enter P%d required memory : ", i+1);
        scanf("%d", &pro[i].requied);
        pro[i].isAllocated = 0;
    }
    printf("\nEnter Memory space\n");
    for (int i=0; i<noMemory; i++){
        printf("Enter M%d memory space : ", i+1);
        scanf("%d", &mem[i].space);
        mem[i].isFilled = 0;
    }
    for (int i=0; i<noProcess; i++){
        for (int j=0; j<noMemory; j++){
            if(pro[i].requied <= mem[j].space && mem[j].isFilled != 1){
                pro[i].isAllocated = 1;
                mem[j].isFilled = 1;
                mem[j].hole = mem[j].space - pro[i].requied;
                mem[j].pID = i+1;
                break;
            }
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