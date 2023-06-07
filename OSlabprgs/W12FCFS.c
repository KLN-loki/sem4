//FCFS Disk scheduling algorithm

#include <stdio.h>
#include <math.h>

int main(){
    int n;
    printf("Enter the number of sectors : ");
    scanf("%d", &n);
    int req[n];
    printf("Enter the sector position : ");
    for(int i = 0; i < n; i++){
        scanf("%d", &req[i]);
    }
    int cp;
    printf("Enter the initial sector position : ");
    scanf("%d", &cp);
    int Tseek = 0;
    Tseek += abs(cp - req[0]);
    for (int i = 1; i < n; i++){
        Tseek += abs(req[i] - req[i-1]);
    }
    printf("Total seek time : %d", Tseek);
    return 0;
}