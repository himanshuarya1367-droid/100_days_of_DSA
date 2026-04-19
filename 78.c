#include <stdio.h>

#define MAX 100
#define INF 999999

int n, m;
int graph[MAX][MAX];

int minKey(int key[], int mstSet[]) {
    int min = INF, min_index = -1;
    int v;

    for (v = 1; v <= n; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

int primMST() {
    int parent[MAX];
    int key[MAX];
    int mstSet[MAX];
    int i, count, u, v;
    int totalWeight = 0;

    // Initialize
    for (i = 1; i <= n; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }

    key[1] = 0;       // Start from node 1
    parent[1] = -1;

    for (count = 1; count < n; count++) {
        u = minKey(key, mstSet);
        mstSet[u] = 1;

        for (v = 1; v <= n; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Calculate total weight
    for (i = 2; i <= n; i++) {
        totalWeight += graph[i][parent[i]];
    }

    return totalWeight;
}

int main() {
    int i, u, v, w;

    scanf("%d %d", &n, &m);

    // Initialize graph with 0
    for (i = 1; i <= n; i++) {
        for (v = 1; v <= n; v++) {
            graph[i][v] = 0;
        }
    }

    // Input edges
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // Undirected graph
    }

    printf("%d\n", primMST());

    return 0;
}
