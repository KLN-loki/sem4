#include <stdio.h>

void Merge(int a[], int low, int mid, int high);

void MergeSort(int a[], int low, int high){
    if(low < high){
        int mid = (low+high)/2;
        MergeSort(a, low, mid);
        MergeSort(a, mid+1, high);
        Merge(a, low, mid, high);
    }
}

void Merge(int a[], int low, int mid, int high){
    int i = low, j = mid+1, k = 0;
    int temp[high-low+1];
    while(i <= mid && j <= high){
        if(a[i] < a[j]){
            temp[k] = a[i];
            i++;
        }
        else {
            temp[k] = a[j];
            j++;
        }
        k++;
    }
    if(i <= mid){
        while(i <= mid){
            temp[k] = a[i];
            k++;
            i++;
        }
    }
    else{
        while(j <= high){
            temp[k] = a[j];
            k++;
            j++;
        }
    }
    for(k = 0; k < high-low+1; k++){
        a[k+low] = temp[k];
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
    MergeSort(a, 0, n-1);
    printf("Sorted array using Merge Sort : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}