#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int n, m;

void dfs(int node) {
    int i;
    visited[node] = 1;

    for(i = 1; i <= n; i++) {
        if(graph[node][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int i, j, u, v;
    int count = 0;

    scanf("%d %d", &n, &m);

    // Initialize
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }

    // Input edges
    for(i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    // DFS from node 1
    dfs(1);

    // Count visited nodes
    for(i = 1; i <= n; i++) {
        if(visited[i] == 1) {
            count++;
        }
    }

    if(count == n)
        printf("CONNECTED");
    else
        printf("NOT CONNECTED");

    return 0;
}
