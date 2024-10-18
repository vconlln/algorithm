#include<stdio.h>

void loveYou(int flag[], int n){
    printf("I Am Iron Man!\n");
    for(int i=0; i<n; i++){
        if(flag[i]==n){
            printf("I Love You %d\n", n);
            break;
        }
    }
}

int main(){
    int flag[30] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
    loveYou(flag, 20);
    return 0;
}