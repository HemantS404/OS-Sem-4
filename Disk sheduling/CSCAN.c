#include <stdio.h>
#include <stdlib.h>

void main(){
    int disk, request, track[10], head, totalTrackMovement=0, end=0;
    printf("Enter number of disk tracks : ");
    scanf("%d", &disk);
    printf("Enter curent position of head : ");
    scanf("%d", &head);
    printf("Enter number of request in queue : ");
    scanf("%d", &request);
    printf("Enter request queue : ");
    for(int i=0; i<request; i++){
        scanf("%d", &track[i]);
    }

    for(int i=1; i<request; i++){
        int j = i-1;
        int key = track[i];
        while(j>=0 && key < track[j]){
            track[j+1]= track[j];
            j--;
        }
        track[j+1] = key;
    }
    for(int i=0; i<request; i++){
        if(track[i] < head){
            end = track[i];
        }
        else{
            break;
        }
    }
    totalTrackMovement = abs(disk-1 - head) + abs(disk-1 - 0) + abs(end - 0);
    printf("Total Track Movement : %d", totalTrackMovement);
}