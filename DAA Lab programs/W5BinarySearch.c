#include <stdio.h>

int BinarySearch(int a[], int low, int high, int key){
    if(low <= high){
        int mid = (low+high)/2;
        if(a[mid] == key) return mid;
        else if(key > a[mid]) BinarySearch(a, mid+1, high, key);
        else BinarySearch(a, low, mid-1, key);
    }
    else return -1;
}
int main(){
    int n;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the array elements : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int key;
    printf("Enter key : ");
    scanf("%d", &key);
    int result = BinarySearch(a, 0, n-1, key);
    if(result == -1) printf("Element not found.");
    else printf("Element found at index %d.", result);
    return 0;
}