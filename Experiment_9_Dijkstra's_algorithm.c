```c
#include <stdio.h>

#define MAX 100
#define INF 999999

void dijkstra(int graph[MAX][MAX], int n, int src)
{
    int dist[MAX], visited[MAX];
    int i, j, u, min;

    for (i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (i = 0; i < n - 1; i++) {
        min = INF;
        u = -1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && graph[u][j] > 0 &&
                dist[u] != INF &&
                dist[u] + graph[u][j] < dist[j]) {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    printf("\nVertex\tShortest Distance\n");

    for (i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("%d\tUnreachable\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }
}

int main()
{
    int graph[MAX][MAX];
    int n, src, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 for no edge):\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);

    if (n < 1 || n > MAX || src < 0 || src >= n) {
        printf("Invalid input.\n");
        return 1;
    }

    dijkstra(graph, n, src);

    return 0;
}
```
