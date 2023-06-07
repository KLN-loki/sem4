#include <stdio.h>

void swap(float *a, float *b){
    float temp = *a;
    *a = *b;
    *b = temp;
}
void FKnapsack(float w[], float p[], int n, int m){
    float pd[n], x[n];
    for (int i = 0; i < n; i++){
        pd[i] = p[i]/w[i];
        x[i] = 0;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n-i-1; j++){
            if(pd[j] < pd[j+1]){
                swap(&pd[j], &pd[j+1]);
                swap(&w[j], &w[j+1]);
                swap(&p[j], &p[j+1]);
            }
        }
    }
    int rm = m;
    float tp = 0;
    for (int i = 0; i < n; i++){
        if(w[i] <= rm){
            rm -= w[i];
            x[i] = 1.0;
            tp += p[i];
        }
        else {
            x[i] = rm/w[i];
            tp += x[i]*p[i];
            break;
        }
    }
    printf("Solution is : \n");
    for (int i = 0; i < n; i++){
        printf("%f  ", x[i]);
    }
    printf("\nTotal profit is %f", tp);
}

int main(){
    int n;
    printf("Enter the number of items : ");
    scanf("%d", &n);
    float w[n], p[n];
    printf("Enter the weights and profits : ");
    for (int i = 0; i < n; i++){
        scanf("%f%f", &w[i], &p[i]);
    }
    int m;
    printf("Enter the knapsack capacity : ");
    scanf("%d", &m);
    FKnapsack(w, p, n, m);
    return 0;
}