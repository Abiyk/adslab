#include <stdio.h>
#define INF 9999

int main()
{
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int cost[10][10], visited[10] = {0};

    printf("Enter the adjacency matrix:\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    visited[0] = 1;
    int edges = 0;

    printf("Edges in MST:\n");

    while (edges < n - 1)
    {
        int min = INF, a = -1, b = -1;

        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!visited[j] && cost[i][j] != 0 && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        printf("%d -- %d (weight = %d)\n", a, b, min);

        visited[b] = 1;
        edges++;
    }

    return 0;
}
