#include <stdio.h>
#include <limits.h>

int n;

void printPath(int path[][n], int src, int dest) {
    if (path[src][dest] == -1) {
        printf("%d", src);
    } else {
        printPath(path, src, path[src][dest]);
        printf(" %d", dest);
    }
}

void printAllPaths(int dist[][n], int path[][n]) {
    for (int src = 0; src < n; src++) {
        for (int dest = 0; dest < n; dest++) {
            if (src != dest) {
                printf("Shortest path from %d to %d: ", src, dest);
                if (dist[src][dest] == INT_MAX) {
                    printf("No path exists\n");
                } else {
                    printPath(path, src, dest);
                    printf("\n");
                }
            }
        }
    }
}

void floydWarshall(int graph[][n]) {
    int dist[n][n];
    int path[n][n];
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j] == -1) {
                dist[i][j] = INT_MAX;
            } else {
                dist[i][j] = graph[i][j];
            }
            if (graph[i][j] != INT_MAX && i != j) {
                path[i][j] = i;
            } else {
                path[i][j] = -1;
            }
        }
    }
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }
    printAllPaths(dist, path);
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    int graph[n][n];
    printf("Enter the cost adjacency matrix (-1 for infinity):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if(graph[i][j] == -1) graph[i][j] = INT_MAX;
        }
    }
    floydWarshall(graph);
    return 0;
}
