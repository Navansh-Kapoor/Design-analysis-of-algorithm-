#include <stdio.h>
#include <limits.h>

struct Edge {
    int u, v, w;
};

void BellmanFord(int V, int E, struct Edge edges[],
                 int src) {
    int dist[V];

    // Initialize distances
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INT_MAX &&
                dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Detect negative-weight cycle
    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INT_MAX &&
            dist[u] + w < dist[v]) {
            printf("Negative-weight cycle detected!\n");
            return;
        }
    }

    // Print shortest distances
    printf("Vertex\tDistance from Source\n");

    for (int i = 0; i < V; i++) {
        printf("%d\t", i);

        if (dist[i] == INT_MAX)
            printf("INF\n");
        else
            printf("%d\n", dist[i]);
    }
}

int main() {
    int V, E, src;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    struct Edge edges[E];

    printf("Enter edges (source destination weight):\n");

    for (int i = 0; i < E; i++) {
        scanf("%d %d %d",
              &edges[i].u,
              &edges[i].v,
              &edges[i].w);
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    BellmanFord(V, E, edges, src);

    return 0;
}
