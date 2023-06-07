#include <stdio.h>

int max(int a, int b){
    return (a > b) ? a : b;
}

int Knapsack(int w[], int p[], int n, int m){
    int dp[n+1][m+1];
    for(int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else {
                if(w[i-1] > j){
                    dp[i][j] = dp[i-1][j];
                }
                else {
                    dp[i][j] = max(p[i-1] + dp[i-1][j-w[i-1]], dp[i-1][j]);
                }
            }
        }
    }
    //backtracking x values
    int x[n], i = n, j = m;
    while(i > 0 && j > 0){
        if(dp[i][j] == dp[i-1][j]){
            x[i-1] = 0;
        }
        else {
            x[i-1] = 1;
            j -= w[i-1];
        }
        i--;
    }
    printf("Solution Vector : ");
    for(int i = 0; i < n; i++){
        printf("%d ", x[i]);
    }
    return dp[n][m];
}

int main(){
    int n;
    printf("Enter the number of items : ");
    scanf("%d", &n);
    int w[n], p[n], x[n];
    printf("Enter the weights and profits : ");
    for (int i = 0; i < n; i++){
        scanf("%d%d", &w[i], &p[i]);
        x[i] = 0;
    }
    int m;
    printf("Enter the knapsack capacity : ");
    scanf("%d", &m);
    int tp = Knapsack(w, p, n, m);
    printf("\nTotal profit = %d", tp);
    return 0;
}