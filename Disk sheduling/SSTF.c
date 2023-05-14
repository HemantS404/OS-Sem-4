#include <stdio.h>
#include <stdlib.h>

int track[10], isVisited[10];

int shortestMovement(int head, int request){
    int nearestTrack;
    for(int i=0; i<request; i++){
        if(isVisited[i]!=1){
            nearestTrack = i;
            break;
        }
    }
    for(int i=nearestTrack; i<request; i++){
        if(isVisited[i]!=1 && abs(head - track[nearestTrack]) > abs(head - track[i])){
            nearestTrack = i;
        }
    }
    return nearestTrack;
}

void main(){
    int disk, request, head, totalTrackMovement=0, visited=0;
    printf("Enter number of disk tracks : ");
    scanf("%d", &disk);
    printf("Enter curent position of head : ");
    scanf("%d", &head);
    printf("Enter number of request in queue : ");
    scanf("%d", &request);
    for(int i=0; i<request; i++){
        isVisited[i]=0;
    }
    printf("Enter request queue : ");
    for(int i=0; i<request; i++){
        scanf("%d", &track[i]);
    }
    while(visited < request){
        int nearestTrack = shortestMovement(head, request);
        totalTrackMovement += abs(track[nearestTrack] - head);
        isVisited[nearestTrack] = 1;
        visited++;
        head = track[nearestTrack];
    }
    printf("Total Track Movement : %d", totalTrackMovement);
}