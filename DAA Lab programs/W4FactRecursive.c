#include <stdio.h>

long long int factRecursive(int n){
    if(n <= 1) return 1;
    else return n*factRecursive(n-1);
}

int main(){
    int n;
    printf("Enter the number : ");
    scanf("%d", &n);
    long long int factorial = factRecursive(n);
    printf("Factorial of %d is %lld", n, factorial);
    return 0;
}