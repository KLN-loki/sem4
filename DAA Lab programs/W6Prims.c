#include <stdio.h>
#include <limits.h>

#define MAX_NODES 100

void prim(int numNodes, int graph[MAX_NODES][MAX_NODES]){
    int selected[MAX_NODES];
    int minCost = 0;
    // Initialize selected[] array
    for (int i = 0; i < numNodes; i++)
        selected[i] = 0;
    // Select the first node as the starting node
    selected[0] = 1;
    // Print the edges of the minimum spanning tree
    printf("Edges of the Minimum Spanning Tree:\n");
    for (int count = 0; count < numNodes - 1; count++){
        int minWeight = INT_MAX;
        int u = -1, v = -1;
        // Find the edge with the minimum weight
        for (int i = 0; i < numNodes; i++){
            if (selected[i]){
                for (int j = 0; j < numNodes; j++){
                    if (!selected[j] && graph[i][j] && graph[i][j] < minWeight){
                        minWeight = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        if (u != -1 && v != -1){
            // Print the selected edge
            printf("%d - %d\n", u, v);
            selected[v] = 1;
            minCost += minWeight;
        }
    }
    printf("Minimum cost: %d\n", minCost);
}

int main(){
    int numNodes;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &numNodes);
    int graph[MAX_NODES][MAX_NODES];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numNodes; i++){
        for (int j = 0; j < numNodes; j++){
            scanf("%d", &graph[i][j]);
        }
    }
    prim(numNodes, graph);
    return 0;
}
