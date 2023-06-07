#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minheap(int a[], int i, int n){
    int min = i;
    int lnode = 2*i+1, rnode = 2*i+2;
    if(rnode < n){
        if(a[lnode] < a[min]) min = lnode;
        if(a[rnode] < a[min]) min = rnode;
    }
    else if(lnode < n){
        if(a[lnode] < a[min]) min = lnode;
    }
    if(min != i){
        swap(&a[min], &a[i]);
        minheap(a, min, n);
    }
}
int main(){
    int n;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the array elements : ");
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for (int i = (n/2)-1; i >= 0; i--){
        minheap(a, i, n);
    }
    printf("Min heap of the array : ");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}