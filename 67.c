#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n; // number of vertices

// Function to push into stack
void push(int v) {
    stack[++top] = v;
}

// DFS function
void dfs(int v) {
    int i;
    visited[v] = 1;

    for(i = 0; i < n; i++) {
        if(adj[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }

    push(v); // push after visiting all neighbors
}

// Topological Sort Function
void topologicalSort() {
    int i;

    for(i = 0; i < n; i++) {
        visited[i] = 0;
    }

    for(i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }

    // Print stack in reverse order
    printf("Topological Order: ");
    for(i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}

// Main function
int main() {
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    topologicalSort();

    return 0;
}
