#include <stdio.h>
#include <string.h>


int max(int a, int b){
    return (a > b) ? a : b;
}

int LCSInt(int s1[], int s2[], int n){
    int dp[n+1][n+1], i, j;
    for (i = 0; i <= n; i++)    {
        for (j = 0; j <= n; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else{
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
    }
    // Backtracking for LCS;
    i = n, j = n;
    int len = dp[n][n];
    int lcs[len];
    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            lcs[len-1] = s1[i-1];
            i--;
            j--;
            len--;
        }
        else {
            if(max(dp[i-1][j], dp[i][j-1]) == dp[i-1][j]) i--;
            else j--;
        }
    }
    printf("LCS : ");
    for(int k = 0; k < dp[n][n]; k++){
        printf("%d ", lcs[k]);
    }
    return dp[n][n];
}

void InsertionSort(int s2[], int n){
    for(int i = 1; i < n; i++){
        int j = i, key = s2[i];
        while(j > 0 && s2[j-1] > key){
            s2[j] = s2[j-1];
            j--;
        }
        s2[j] = key;
    }
}

int main(){
    int n;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    int s1[n], s2[n];
    printf("Enter the array elements : ");
    for (int i = 0; i < n; i++){
        scanf("%d", &s1[i]);
        s2[i] = s1[i];
    }
    InsertionSort(s2, n);
    int result = LCSInt(s1, s2, n);
    printf("\nLenght of LCS is %d", result);
    return 0;
}

// void printlcs(int dp[][100], int s1[] ,int s2[], int i, int j){
//     if(dp[i][j] == 0) return;
//     if(s1[i-1] == s2[j-1]){
//         printlcs(dp, s1, s2, i-1, j-1);
//         printf("%d", s1[i-1]);
//     }
//     else if(dp[i-1][j] > dp[i][j-1]){
//         printlcs(dp, s1, s2, i-1, j);
//     }
//     else {
//         printlcs(dp, s1, s2, i, j-1);
//     }
// }
    // printlcs(dp, s1, s2, n, n);