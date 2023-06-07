#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxheap(int a[], int i, int n){
    int max = i;
    int lnode = 2*i+1, rnode = 2*i+2;
    if(rnode < n){
        if(a[lnode] > a[max]) max = lnode;
        if(a[rnode] > a[max]) max = rnode;
    }
    else if(lnode < n){
        if(a[lnode] > a[max]) max = lnode;
    }
    if(max != i){
        swap(&a[max], &a[i]);
        maxheap(a, max, n);
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
        maxheap(a, i, n);
    }
    for(int i = n-1; i >= 0; i--){
        swap(&a[0], &a[i]);
        for(int j = (i/2)-1; j >= 0; j--){
            maxheap(a, j, i);
        }
    }
    printf("Sorted array using heapsort : ");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}