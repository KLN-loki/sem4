//10. Implement Banker’s algorithm for the purpose of Deadlock avoidance

#include <stdio.h>
#include <unistd.h>

int main() {
    int n, m, i, j, k;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);
    int alloc[n][m];
    printf("Enter the allocation matrix: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }
    int max[n][m];
    printf("Enter the maximum matrix: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }
    int avail[m];
    printf("Enter the available resources: \n");
    for (i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
    }
    int f[n];
    for (k = 0; k < n; k++) {
        f[k] = 0;
    }
    int need[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    int ans[n];
    int ind = 0;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    ans[ind++] = i;
                    for (j = 0; j < m; j++) {
                        avail[j] += alloc[i][j];
                    }
                    f[i] = 1;
                }
            }
        }
    }
    int flag = 1;
    for (i = 0; i < n; i++) {
        if (f[i] == 0) {
            flag = 0;
            break;
        }
    }
    if (flag == 0) {
        printf("The system is not in a safe state.\n");
    } else {
        printf("The system is in a safe state.\n");
        printf("Safe sequence: ");
        for (i = 0; i < n - 1; i++) {
            printf("P%d -> ", ans[i]);
        }
        printf("P%d\n", ans[n - 1]);
    }
    return 0;
}
