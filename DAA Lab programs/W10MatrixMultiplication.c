#include <stdio.h>
#include <limits.h>

int n;

void MATRIX_CHAIN_ORDER(int *r, int n, int c[][n + 1], int kay[][n + 1]) {
    int i, j, k, l, q;
    for (i = 1; i <= n; i++) {
        c[i][i] = 0;
    }
    for (l = 2; l <= n; l++) {
        for (i = 1; i <= n - l + 1; i++) {
            j = i + l - 1;
            c[i][j] = INT_MAX;

            for (k = i; k <= j - 1; k++) {
                q = c[i][k] + c[k + 1][j] + r[i - 1] * r[k] * r[j];
                if (q < c[i][j]) {
                    c[i][j] = q;
                    kay[i][j] = k;
                }
            }
        }
    }
}

void PRINT_OPTIMAL_PARENS(int kay[][n + 1], int i, int j) {
    if (i == j) {
        printf("M%d", i);
    }
    else {
        printf("(");
        PRINT_OPTIMAL_PARENS(kay, i, kay[i][j]);
        PRINT_OPTIMAL_PARENS(kay, kay[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    int r[n + 1];
    printf("Enter the dimensions of the matrices: ");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &r[i]);
    }
    int c[n + 1][n + 1];
    int kay[n + 1][n + 1];
    int i, j;
    MATRIX_CHAIN_ORDER(r, n, c, kay);
    printf("Minimum number of scalar multiplications: %d\n", c[1][n]);
    printf("Optimal parenthesis ordering: ");
    PRINT_OPTIMAL_PARENS(kay, 1, n);
    return 0;
}
