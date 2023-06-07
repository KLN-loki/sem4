#include <stdio.h>

int GcdIterative(int m, int n){
    for(int i = n; i > 0; i--){
        if(m%i == 0 && n%i == 0) return i;
    }
    return 1;
}

int main(){
    int m, n;
    printf("Enter the m and n : ");
    scanf("%d%d", &m, &n);
    if(m < n){
        int temp = m;
        m = n;
        n = temp;
    }
    int result = GcdIterative(m, n);
    printf("Gcd of %d and %d is %d.", m, n, result);
    return 0;
}