#include <stdio.h>
#include <string.h>

int max(int a, int b){
    return (a > b) ? a : b;
}

int LCS(char s1[], char s2[]){
    int x, y;
    x = strlen(s1);
    y = strlen(s2);
    int dp[x+1][y+1];
    for (int i = 0; i <= x; i++)    {
        for (int j = 0; j <= y; j++){
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
    int i = x, j = y, len = dp[x][y];
    char lcs[len+1];
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
    printf("LCS : %s\n", lcs);
    return dp[x][y];
}
int main(){
    char s1[100], s2[100];
    printf("Enter string 1 : ");
    scanf("%s", s1);
    printf("Enter string 2 : ");
    scanf("%s", s2);
    int len = LCS(s1, s2);
    printf("Lenght of LCS is %d", len);
    return 0;
}