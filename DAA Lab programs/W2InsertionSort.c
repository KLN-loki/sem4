#include <stdio.h>

void InsertionSort(int a[], int n){
    for(int i = 1; i < n; i++){
        int j = i;
        int key = a[i];
        while(j >= 0 && a[j-1] > key){
            a[j] = a[j-1];
            j--;
        }
        a[j] = key;
    }
}
int main(){
    int n;
    printf("Enter the Size of the array : ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the array elements : ");
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    InsertionSort(a, n);
    printf("Sorted using Insertion Sort : ");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}