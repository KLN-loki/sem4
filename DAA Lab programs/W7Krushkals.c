#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 100

int cost[MAX_SIZE][MAX_SIZE];
int parent[MAX_SIZE];

int find(int i) {
    while (parent[i] != 0)
        i = parent[i];
    return i;
}

int Union(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

void kruskalsAlgorithm(int n) {
    int i, j, k, a, b, u, v, ne = 1;
    int min, mincost = 0;

    printf("The edges of Minimum Cost Spanning Tree are\n");
    while (ne < n) {
        for (i = 0, min = INT_MAX; i <= n; i++) {
            for (j = 0; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (Union(u, v)) {
            printf("%d edge (%d,%d) = %d\n", ne++, a, b, min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = INT_MAX;
    }
    printf("\nMinimum cost = %d\n", mincost);
}

int main() {
    int n;
    printf("\nImplementation of Kruskal's algorithm\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    // Initialize parent array
    for (int i = 0; i < MAX_SIZE; i++) {
        parent[i] = 0;
    }
    printf("Enter the cost adjacency matrix (-1 for infinity):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == -1) cost[i][j] = INT_MAX;
        }
    }
    kruskalsAlgorithm(n);
    return 0;
}
