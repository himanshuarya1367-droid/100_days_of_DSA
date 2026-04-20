#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, m;
    int i, j;

    // Adjacency matrix
    int graph[MAX][MAX];

    // Distance array
    int dist[MAX];

    // Visited array
    int visited[MAX];

    int u, v, w;
    int source;

    // Input number of vertices and edges
    scanf("%d %d", &n, &m);

    // Initialize graph with large values
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            graph[i][j] = INT_MAX;
        }
    }

    // Input edges
    for(i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // remove this line if graph is directed
    }

    // Input source
    scanf("%d", &source);

    // Initialize distances and visited
    for(i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[source] = 0;

    // Dijkstra Algorithm
    for(i = 1; i <= n; i++) {
        int min = INT_MAX;
        int u_min = -1;

        // Find minimum distance vertex
        for(j = 1; j <= n; j++) {
            if(!visited[j] && dist[j] < min) {
                min = dist[j];
                u_min = j;
            }
        }

        if(u_min == -1)
            break;

        visited[u_min] = 1;

        // Update distances
        for(j = 1; j <= n; j++) {
            if(!visited[j] && graph[u_min][j] != INT_MAX &&
               dist[u_min] + graph[u_min][j] < dist[j]) {
                dist[j] = dist[u_min] + graph[u_min][j];
            }
        }
    }

    // Output distances
    for(i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}
