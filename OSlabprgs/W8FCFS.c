// 8. Implement non-pre-emptive/pre-emptive CPU scheduling algorithms to find turnaround
// time and waiting time (minimum 2 from all process scheduling algorithms)

//FCFS

#include <stdio.h>
#include <unistd.h>

int main(){
    int n, i, j, at[20], bt[20], wt[20], tat[20], ct[20];
    float avwt = 0, avtat = 0, avtput = 0;
    printf("Enter n : ");
    scanf("%d", &n);
    printf("Enter arrival time & Brust times : \n");
    for(i = 0; i < n; i++){
        printf("P%d : ", i+1);
        scanf("%d%d", &at[i], &bt[i]);
        avtput += bt[i];
    }
    ct[0] = at[0]+bt[0];
    for(i = 1; i < n; i++){
        if(ct[i-1] < at[i]){
            ct[i] = at[i]+bt[i];
        }
        else{
            ct[i] = ct[i-1]+bt[i];
        }
    }
    for(i = 0; i < n; i++){
        wt[i] = ct[i] - bt[i] - at[i];
        avwt += wt[i];
        tat[i] = ct[i] - at[i];
        avtat += tat[i];
    }
    avtput /= n;
    avwt /= n;
    avtat /= n;
    printf("Average throughput : %f\n", avtput);
    printf("Average waiting time : %f\n", avwt);
    printf("Average turn around time : %f\n", avtat);
    printf("Process\tavt\tbt\tct\twt\ttat\n");
    for(i = 0; i < n; i++){
        printf("P%d    \t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], wt[i], tat[i]);
    }
    return 0;
}