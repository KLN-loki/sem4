#include <stdio.h>
#include <limits.h>

int i, j, k, a, b, u, v, n, ne = 1;
int parent[100];

int size = 0;
struct Heap
{
    int i, j, cost;
} h[100];

void swap(struct Heap *a, struct Heap *b)
{
    struct Heap t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(int i)
{
    int left = 2 * i + 1, right = 2 * i + 2, smallest = i;
    if (left < size && h[left].cost < h[smallest].cost)
        smallest = left;
    if (right < size && h[right].cost < h[smallest].cost)
        smallest = right;
    if (smallest != i)
    {
        swap(&h[smallest], &h[i]);
        minHeapify(smallest);
    }
}

void buildHeap()
{
    for (int i = (size - 2) / 2; i >= 0; i--)
        minHeapify(i);
}

int delmin()
{
    if (size == 0)
        return -1;
    if (size == 1)
    {
        size--;
        return h[0].cost;
    }
    int ret = h[0].cost;
    a = u = h[0].i;
    b = v = h[0].j;
    swap(&h[0], &h[size - 1]);
    size--;
    minHeapify(0);
    return ret;
}

int find(int i)
{
    while (parent[i] != -1)
        i = parent[i];
    return i;
}
int Union(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main()
{
    printf("\n\tImplementation of Kruskal's algorithm\n");
    printf("\nEnter the no. of vertices:");
    scanf("%d", &n);
    int cost[n][n];
    int min, mincost = 0;
    printf("\nEnter the cost adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INT_MAX;
            if (j >= i + 1)
            {
                h[size].i = i;
                h[size].j = j;
                h[size].cost = cost[i][j];
                size++;
            }
        }
    }
    for (i = 0; i < n; i++)
        parent[i] = -1;
    buildHeap();
    printf("The edges of Minimum Cost Spanning Tree are\n");
    while (ne < n)
    {
        min = delmin();
        u = find(u);
        v = find(v);
        if (Union(u, v))
        {
            printf("%d edge (%d,%d) =%d\n", ne++, a, b, min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = INT_MAX;
    }
    printf("\n\tMinimum cost = %d\n", mincost);

    return 0;
}
