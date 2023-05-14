#include <stdio.h>
#include <stdlib.h>

void main(){
    int disk, request, track[10], head, totalTrackMovement=0;
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
    for(int i=0; i<request; i++){
        totalTrackMovement += abs(track[i] - head);
        head = track[i];
    }
    printf("Total Track Movement : %d", totalTrackMovement);
}