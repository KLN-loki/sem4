//SSTF Disk scheduling algorithm

#include <stdio.h>
#include <math.h>
#include <limits.h>

int cp;

int DIffMIn(int req[], int index[50], int n){
    int min = INT_MAX;
    int flag, i;
    for (i = 0; i < n; i++){
        int absolute = abs(cp - req[i]);
        if (absolute < min && index[i] == 0) {
            min = absolute;
            flag = i;
        }
    }
    cp = req[flag];
    index[flag] = 1;
    return min;
}

int main(){
    int n, i;
    printf("Enter the number of sectors : ");
    scanf("%d", &n);
    int req[n];
    printf("Enter the sector position : ");
    for(i = 0; i < n; i++){
        scanf("%d", &req[i]);
    }
    // int cp;
    printf("Enter the initial sector position : ");
    scanf("%d", &cp);
    int index[50] = {0};
    int Tseek = 0;
    for (i = 0; i < n; i++){
        Tseek += DIffMIn(req, index, n);
    }
    printf("%d", Tseek);
    return 0;
}
