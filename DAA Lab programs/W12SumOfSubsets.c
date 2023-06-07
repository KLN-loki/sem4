#include <stdio.h>

void subsetSum(int set[], int subset[], int n, int targetSum, int sum, int k, int start) {
    if (sum == targetSum) {
        for (int i = 0; i < k; i++) {
            printf("%d ", subset[i]);
        }
        printf("\n");
    }
    else if (sum > targetSum || start >= n) {
        return;
    }
    else {
        for (int i = start; i < n; i++) {
            subset[k] = set[i];
            subsetSum(set, subset, n, targetSum, sum + set[i], k + 1, i + 1);
        }
    }
}

void findSubsets(int set[], int n, int targetSum) {
    int subset[n];
    subsetSum(set, subset, n, targetSum, 0, 0, 0);
}

int main() {
    int n;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);
    int set[n];
    printf("Enter the elements of the set: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }
    int targetSum;
    printf("Enter the target sum: ");
    scanf("%d", &targetSum);
    printf("Subsets whose sum is %d:\n", targetSum);
    findSubsets(set, n, targetSum);    
    return 0;
}
