#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int recStack[MAX];
int V;

/* DFS function to detect cycle */
int dfs(int node)
{
    int i;

    if (visited[node] == 0)
    {
        visited[node] = 1;
        recStack[node] = 1;

        for (i = 0; i < V; i++)
        {
            if (graph[node][i])
            {
                /* If not visited, recurse */
                if (!visited[i] && dfs(i))
                    return 1;

                /* If already in recursion stack ? cycle */
                else if (recStack[i])
                    return 1;
            }
        }
    }

    recStack[node] = 0; // remove from stack
    return 0;
}

/* Function to check cycle */
int isCycle()
{
    int i;

    for (i = 0; i < V; i++)
    {
        visited[i] = 0;
        recStack[i] = 0;
    }

    for (i = 0; i < V; i++)
    {
        if (dfs(i))
            return 1;
    }

    return 0;
}

int main()
{
    int i, j, edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    /* Initialize graph */
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            graph[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v) [0-based indexing]:\n");
    for (i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;  // directed edge
    }

    if (isCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
