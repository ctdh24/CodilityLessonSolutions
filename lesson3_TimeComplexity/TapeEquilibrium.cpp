#include <stdlib.h>

int solution(int A[], int N) {
    // write your code in C99 (gcc 4.8.2)
    int sumLeft[N-1];
    int tempSumLeft = 0;
    for(int i = 0; i < N-1; i++){
        tempSumLeft = tempSumLeft + A[i];
        sumLeft[i]=tempSumLeft;
    }
    int tempSumRight = 0;
    for(int i = 1; i < N; i++){
        tempSumRight = tempSumRight + A[i];
    }
    int minDif = abs(sumLeft[0]-tempSumRight);
    //printf("|%d - %d| = %d",sumLeft[0], tempSumRight, minDif);
    for(int i = 1; i < N-1;i++){
        tempSumRight = tempSumRight - A[i];
        int tempDif = abs(sumLeft[i]-tempSumRight);
        //printf("|%d - %d| = %d",sumLeft[i], tempSumRight, tempDif);
        if(minDif > tempDif) minDif = tempDif;
    }
    return minDif;
}