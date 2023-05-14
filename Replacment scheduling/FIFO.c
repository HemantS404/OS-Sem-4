#include <stdio.h>
#include <stdlib.h>

void main(){
    int noFrames, noPages, frames[10], pages[20], frameHead=0, fault=0;
    printf("Enter number of frames : ");
    scanf("%d", &noFrames);
    for (int i=0; i<noFrames; i++){
        frames[i] = -1;
    }
    printf("Enter total number of pages : ");
    scanf("%d", &noPages);
    printf("Enter sequence : ");
    for (int i=0; i<noPages; i++){
        scanf("%d", &pages[i]);
    }
    for (int i=0; i<noPages; i++){
        int count = 0;
        for (int j=0; j<noFrames; j++){
            if (frames[j] != pages[i]){
                count++;
            }else{
                break;
            }
        }
        if(i<noFrames){
            frames[fault] = pages[i];
            fault++;
        }
        else if(count == noFrames){
            fault++;
            frames[frameHead] = pages[i];
            frameHead = (frameHead+1)%noFrames;
        }
        printf("Page : %d\tFrames : ", pages[i]);
        for (int j=0; j<noFrames; j++){
            printf("%d\t", frames[j]);
        }
        printf("\n");
    }
    printf("Page Faults : %d", fault);
}