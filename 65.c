#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n;

// DFS function to detect cycle
int dfs(int node, int parent)
{
    int i;
    visited[node] = 1;

    for (i = 0; i < n; i++)
    {
        if (adj[node][i] == 1)
        {
            if (visited[i] == 0)
            {
                if (dfs(i, node))
                    return 1;
            }
            else if (i != parent)
            {
                return 1; // cycle found
            }
        }
    }
    return 0;
}

int main()
{
    int edges, u, v;
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize matrix and visited array
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
        for (j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for (i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected graph
    }

    // Check all components
    for (i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            if (dfs(i, -1))
            {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}
