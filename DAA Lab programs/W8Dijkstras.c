#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_NODES 100

void printPath(int previous[], int node) {
    if (previous[node] == -1) {
        printf("%d", node);
        return;
    }
    printPath(previous, previous[node]);
    printf(" -> %d", node);
}

void dijkstra(int graph[MAX_NODES][MAX_NODES], int startNode, int numNodes) {
    int distances[MAX_NODES];
    bool visited[MAX_NODES];
    int previous[MAX_NODES];
    for (int i = 0; i < numNodes; i++) {
        distances[i] = INT_MAX;
        visited[i] = false;
        previous[i] = -1;
    }
    distances[startNode] = 0;
    for (int count = 0; count < numNodes - 1; count++) {
        int minDistance = INT_MAX;
        int minIndex = -1;
        for (int i = 0; i < numNodes; i++) {
            if (!visited[i] && distances[i] < minDistance) {
                minDistance = distances[i];
                minIndex = i;
            }
        }
        if (minIndex == -1) {
            // No more nodes to visit
            break;
        }
        visited[minIndex] = true;
        for (int i = 0; i < numNodes; i++) {
            if (!visited[i] && graph[minIndex][i] != INT_MAX &&
                distances[minIndex] != INT_MAX &&
                distances[minIndex] + graph[minIndex][i] < distances[i]) {
                distances[i] = distances[minIndex] + graph[minIndex][i];
                previous[i] = minIndex;
            }
        }
    }
    printf("Shortest paths from the start node (%d):\n", startNode);
    for (int i = 0; i < numNodes; i++) {
        if (i != startNode) {
            printf("Node %d -> Node %d: ", startNode, i);
            if (distances[i] == INT_MAX) {
                printf("No path\n");
            } else {
                printPath(previous, i);
                printf("\n");
            }
        }
    }
}

int main() {
    int numNodes, startNode;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &numNodes);
    int graph[MAX_NODES][MAX_NODES];
    printf("Enter the cost adjacency matrix (-1 for infinity):\n");
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == -1)
                graph[i][j] = INT_MAX;
        }
    }
    printf("Enter the starting node: ");
    scanf("%d", &startNode);
    dijkstra(graph, startNode, numNodes);
    return 0;
}
