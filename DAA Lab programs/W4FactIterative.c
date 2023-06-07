#include <stdio.h>

long long int factIterative(int n){
    long long int factorial = 1;
    for(int i = n; i > 0; i--){
        factorial *= i;
    }
    return factorial;
}

int main(){
    int n;
    printf("Enter the number : ");
    scanf("%d", &n);
    long long int factorial = factIterative(n);
    printf("Factorial of %d is %lld", n, factorial);
    return 0;
}