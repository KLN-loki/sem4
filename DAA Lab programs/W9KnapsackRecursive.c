#include <stdio.h>

int max(int a, int b){
    return (a > b) ? a : b;
}

int Knapsack(int w[], int p[], int k, int n, int m){
    if(k == n){
        if(w[k] <= m) return p[k];
        else return 0;
    }
    else if(k < n){
        if(w[k] > m){
            return Knapsack(w, p, k+1, n, m);
        }
        else{
            return max(Knapsack(w, p, k+1, n, m), p[k]+Knapsack(w, p, k+1, n, m-w[k]));
        }
    }
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
    int tp = Knapsack(w, p, 0, n-1, m);
    printf("Total profit = %d", tp);
    return 0;
}