#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];   // Adjacency matrix
int indegree[MAX];   // In-degree array
int queue[MAX];      // Queue
int n;               // Number of vertices

void topologicalSort() {
    int front = 0, rear = -1;
    int i, j, count = 0;
    int result[MAX];

    // Step 1: Initialize indegree of all vertices to 0
    for (i = 0; i < n; i++) {
        indegree[i] = 0;
    }

    // Step 2: Calculate indegree
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    // Step 3: Add vertices with indegree 0 to queue
    for (i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[++rear] = i;
        }
    }

    // Step 4: Process queue
    while (front <= rear) {
        int vertex = queue[front++];
        result[count++] = vertex;

        // Reduce indegree of adjacent vertices
        for (i = 0; i < n; i++) {
            if (adj[vertex][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    queue[++rear] = i;
                }
            }
        }
    }

    // Step 5: Check for cycle
    if (count != n) {
        printf("Graph has a cycle! Topological sorting not possible.\n");
        return;
    }

    // Step 6: Print result
    printf("Topological Order: ");
    for (i = 0; i < count; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

int main() {
    int i, j, edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v) where u -> v:\n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    topologicalSort();

    return 0;
}
