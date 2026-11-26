#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[10][10], parent[10];
    int a, b, u, v, min, edges = 0, total = 0;

    printf("Enter cost adjacency matrix (0 = no edge):\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    printf("\nEdges selected:\n");

    while (edges < n - 1)
    {
        min = 9999;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (cost[i][j] != 0 && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }

        u = a;
        while (parent[u] != u)
            u = parent[u];

        v = b;
        while (parent[v] != v)
            v = parent[v];

        if (u != v) {
            printf("%d => %d (cost = %d)\n", a, b, min);
            parent[u] = v;
            total += min;
            edges++;
        }

        cost[a][b] = cost[b][a] = 9999;
    }

    printf("\nTotal minimum cost = %d\n", total);

    return 0;
}
