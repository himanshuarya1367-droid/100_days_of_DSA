#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n;

/* DFS Function */
void dfs(int v)
{
    int i;
    visited[v] = 1;

    for(i = 1; i <= n; i++)
    {
        if(adj[v][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}

int main()
{
    int m, i, u, v;
    int components = 0;

    /* Input */
    scanf("%d %d", &n, &m);

    /* Initialize adjacency matrix */
    for(i = 1; i <= n; i++)
    {
        int j;
        for(j = 1; j <= n; j++)
        {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }

    /* Read edges */
    for(i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;  // Undirected graph
    }

    /* Count components */
    for(i = 1; i <= n; i++)
    {
        if(visited[i] == 0)
        {
            dfs(i);
            components++;
        }
    }

    /* Output */
    printf("%d\n", components);

    return 0;
}
