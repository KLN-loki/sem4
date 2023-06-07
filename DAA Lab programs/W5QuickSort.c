#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high){
    int pivot = a[low];
    int i = low+1, j = high;
    while(i <= j){
        while(a[i] <= pivot) i++;
        while(a[j] > pivot) j--;
        if(i <= j){
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[low], &a[j]);
    return j;
}

void QuickSort(int a[], int low, int high){
    if(low < high){
        int p = partition(a, low, high);
        QuickSort(a, low, p-1);
        QuickSort(a, p+1, high);
    }
}

int main(){
    int n;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the array Elements : ");
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    QuickSort(a, 0, n-1);
    printf("Sorted array using Quick Sort : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}