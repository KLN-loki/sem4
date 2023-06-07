// // 8. Implement non-pre-emptive/pre-emptive CPU scheduling algorithms to find turnaround
// // time and waiting time (minimum 2 from all process scheduling algorithms)

// //RoundRobin

#include <stdio.h>
#include <unistd.h>

int main() {
    int n, i, j, tq, at[20], bt[20], wt[20], tat[20], ct[20], readyQ[20], tempbt[20], count;
    float avwt = 0, avtat = 0, avtput = 0;    
    printf("Enter n : ");
    scanf("%d", &n);
    printf("Enter arrival time & burst times : \n");
    for (i = 0; i < n; i++) {
        printf("P%d : ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
        tempbt[i] = bt[i];
        avtput += bt[i];
    }
    printf("Enter time Quantum : ");
    scanf("%d", &tq);
    count = n;
    j = 0;
    int time = 0;
    while (count) {
        for (i = 0; i < n; i++) {
            if (tempbt[i] > 0) {
                if (tempbt[i] > tq) {
                    time += tq;
                    tempbt[i] -= tq;
                } else {
                    time += tempbt[i];
                    wt[i] = time - at[i] - bt[i];
                    tempbt[i] = 0;
                    ct[i] = time;
                    tat[i] = bt[i] + wt[i];
                    avwt += wt[i];
                    avtat += tat[i];
                    count--;
                }
            }
        }
    }
    avtput /= n;
    avwt /= n;
    avtat /= n;
    printf("Average throughput : %f\n", avtput);
    printf("Average waiting time : %f\n", avwt);
    printf("Average turn around time : %f\n", avtat);
    printf("Process\tavt\tbt\tct\twt\ttat\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], wt[i], tat[i]);
    }
    return 0;
}
