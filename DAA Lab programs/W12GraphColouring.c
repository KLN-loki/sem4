#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int x[50] = {0};

void PrintValues(int n){
    printf("Solution Vector : ");
    for(int i = 0; i < n; i++){
        printf("%d ", x[i]+1);
    }
    exit(0);
}

bool NextValue(int g[][50], int n, int k, int i){
    for(int j = 0; j < k; j++){
        if((g[k][j] == 1 || g[j][k] == 1) && x[j] == i){
            return false;
        }
    }
    return true;
}

void GraphColouring(int g[][50], int n, int m, int k){
    for(int i = 0; i < m; i++){
        if(NextValue(g, n, k, i)){
            x[k] = i;
            if(k == n-1){
                PrintValues(n);
            }
            else {
                GraphColouring(g, n, m, k+1);
            }
        }
    }
}

int main(){
    int n;
    printf("Enter number of node(n) : ");
    scanf("%d", &n);
    int g[n][50];
    printf("Enter adjacency matrix : ");
    int m = 0;
    for(int i = 0; i < n; i++){
        int temp = 0;
        for(int j = 0; j < n; j++){
            scanf("%d", &g[i][j]);
            if(g[i][j] == 1) temp++;
        }
        if(temp > m) m = temp;
    }
    GraphColouring(g, n, m+1, 0);
    return 0;
}