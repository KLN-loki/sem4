#include <stdio.h>

void maxmin(int a[], int low, int high, int *min, int *max){
    if(low == high){
        *min = a[low];
        *max = a[low];
    }
    else if(high-low == 1){
        if(a[low] < a[high]){
            *min = a[low];
            *max = a[high];
        }
        else {
            *min = a[high];
            *max = a[low];
        }
    }
    else {
        int mid = (low+high)/2;
        int lmin, lmax, rmin, rmax;
        maxmin(a, low, mid, &lmin, &lmax);
        maxmin(a, mid+1, high, &rmin, &rmax);
        if(lmin < rmin)
            *min = lmin;
        else 
            *min = rmin;
        if(lmax < rmax)
            *max = rmax;
        else
            *max = lmax; 
    }
}
int main(){
    int n;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int min, max;
    maxmin(a, 0, n-1, &min, &max);
    printf("Maximum = %d\nMinimum = %d", max, min);
    return 0;
}