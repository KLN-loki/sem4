#include <stdio.h>

int GcdRecursive(int m, int n){
    if(m%n == 0) return n;
    else GcdRecursive(n, m%n);
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
    int result = GcdRecursive(m, n);
    printf("Gcd of %d and %d is %d.", m, n, result);
    return 0;
}