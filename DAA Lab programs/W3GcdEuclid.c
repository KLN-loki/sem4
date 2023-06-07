#include <stdio.h>

int GcdEuclid(int m, int n){
    while(m%n != 0){
        int temp = n;
        n = m%n;
        m = temp;
    }
    return n;
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
    int result = GcdEuclid(m, n);
    printf("Gcd of %d and %d is %d.", m, n, result);
    return 0;
}