#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

void PrintValues(int x[], int n){
    printf("Solution Vector : ");
    for(int i = 0; i < n; i++){
        printf("%d ", x[i]+1);
    }
    exit(0);
}

bool place(int k, int i, int x[]){
    for(int j = 0; j < k; j++){
        if((x[j] == i) || (abs(x[j]-i) == abs(j-k))){
            return false;
        }
    }
    return true;
}

void NQueens(int k, int x[], int n){
    for(int i = 0; i < n; i++){
        if(place(k, i, x)){
            x[k] = i;
            if(k == n-1){
                PrintValues(x, n);
                return;
            }
            else {
                NQueens(k+1, x, n);
            }
        }
    }
}

int main(){
    int n;
    printf("Enter the number of queens : ");
    scanf("%d", &n);
    int x[n];
    NQueens(0, x, n);
}