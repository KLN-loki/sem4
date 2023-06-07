#include <stdio.h>
#include <string.h>

int min(int a, int b, int c){
    return (a < b && a < c) ? a : (b < c) ? b : c;
}

int EditDistance(char s1[], char s2[]){
    int x, y;
    x = strlen(s1);
    y = strlen(s2);
    int dp[x+1][y+1];
    for (int i = 0; i <= x; i++)    {
        for (int j = 0; j <= y; j++){
            if(i == 0 || j == 0){
                if(i == 0){
                    dp[i][j] = j;
                }
                else {
                    dp[i][j] = i;
                }
            }
            else{
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
                }
            }
        }
    }
    return dp[x][y];
}
int main(){
    char s1[100], s2[100];
    printf("Enter string 1 : ");
    scanf("%s", s1);
    printf("Enter string 2 : ");
    scanf("%s", s2);
    int len = EditDistance(s1, s2);
    printf("Edit Diistance : %d", len);
    return 0;
}