#include <stdio.h>

void SelectionSort(int a[], int n){
    for(int i = 0; i < n; i++){
        int min = i;
        for(int j = i+1; j < n; j++){
            if(a[j] < a[min]) min = j;
        }
        if(min != i) {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
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
    SelectionSort(a, n);
    printf("Sorted using Selection Sort : ");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}