#include <stdio.h>
#include <stdlib.h>

struct process{
    int allocate[10], maxNeed[10], remaining[10], satisfied;
};
struct process pq[10];

void main(){
    int Resource, totalResource[10], availableResource[10], totalProcess, completed=0;
    printf("Enter total number of resource : ");
    scanf("%d", &Resource);
    printf("Enter Total resources for each resorces : ");
    for (int i=0; i<Resource; i++){
        scanf("%d", &totalResource[i]);
        availableResource[i] = totalResource[i];
    }
    printf("Enter total number of process : ");
    scanf("%d", &totalProcess);
    printf("Enter each process Allocation of process : \n");
    for(int i=0; i<totalProcess; i++){
        pq[i].satisfied = 0;
        for(int j=0; j<Resource; j++){
            scanf("%d", &pq[i].allocate[j]);
            availableResource[j] -= pq[i].allocate[j];
        }
    }
    printf("Enter each process Maximum need of process : \n");
    for(int i=0; i<totalProcess; i++){
        for(int j=0; j<Resource; j++){
            scanf("%d", &pq[i].maxNeed[j]);
        }
    }
    for(int i=0; i<totalProcess; i++){
        for(int j=0; j<Resource; j++){
            pq[i].remaining[j] = pq[i].maxNeed[j] - pq[i].allocate[j];
        }
    }

    printf("\nTotal Resource : \n");
    for (int i=0; i<Resource;i++){
        printf("%d\t", totalResource[i]);
    }
    printf("\nAvailable Resource : \n");
    for (int i=0; i<Resource;i++){
        printf("%d\t", availableResource[i]);
    }
    printf("\n");
    printf("\nAllocation graph : \n");
    for(int i=0; i<totalProcess; i++){
        for(int j=0; j<Resource; j++){
            printf("%d\t", pq[i].allocate[j]);
        }
        printf("\n");
    }
    printf("\nMax Need graph : \n");
    for(int i=0; i<totalProcess; i++){
        for(int j=0; j<Resource; j++){
            printf("%d\t", pq[i].maxNeed[j]);
        }
        printf("\n");
    }
    printf("\nRemaining need graph : \n");
    for(int i=0; i<totalProcess; i++){
        for(int j=0; j<Resource; j++){
            printf("%d\t", pq[i].remaining[j]);
        }
        printf("\n");
    }

    while(completed<totalProcess){
        int satisfiedProcess = -1;
        for(int i=0; i<totalProcess; i++){
            if(pq[i].satisfied!=1){
                int count=0;
                for(int j=0; j<Resource; j++){
                    if(pq[i].remaining[j] <= availableResource[j]){
                        count++;
                    }
                }
                if(count == Resource){
                    satisfiedProcess = i;
                    break;
                }
            }
        }
        if(satisfiedProcess != -1){
            pq[satisfiedProcess].satisfied = 1;
            for(int j=0; j<Resource; j++){
                availableResource[j] += pq[satisfiedProcess].allocate[j];
            }
            printf("P%d\t",satisfiedProcess+1);
            completed++;
        }
        else{
            printf("deadlock");
            break;
        }
    }
}