#include <stdio.h>

#define MAX 100   // maximum number of vertices

int main() {
    int adj[MAX][MAX];
    int n, m;
    int i, j;
    int u, v;
    int choice;

    // Input
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Initialize matrix with 0
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    // Graph type
    printf("Enter 1 for Directed Graph, 2 for Undirected Graph: ");
    scanf("%d", &choice);

    // Input edges
    printf("Enter edges (u v):\n");
    for(i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;

        if(choice == 2) {
            adj[v][u] = 1;
        }
    }

    // Output adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
