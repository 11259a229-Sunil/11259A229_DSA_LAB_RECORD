
#include <stdio.h>
#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int n;

void bfs(int start) {
    int queue[MAX], front = 0, rear = 0;
    int i, curr;

    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");

    while (front < rear) {
        curr = queue[front++];
        printf("%d ", curr);

        for (i = 0; i < n; i++) {
            if (adj[curr][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\n");
}

void dfsUtil(int v) {
    int i;

    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfsUtil(i);
        }
    }
}

void dfs(int start) {
    int i;

    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("DFS Traversal: ");
    dfsUtil(start);
    printf("\n");
}

int main() {
    int edges, i, u, v, start, choice;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    if (edges < 0 || edges > n * (n - 1) / 2) {
        printf("Invalid number of edges.\n");
        return 1;
    }

    // Initialize adjacency matrix
    for (i = 0; i < n; i++) {
        for (v = 0; v < n; v++) {
            adj[i][v] = 0;
        }
    }

    printf("Enter edges (u v) for an undirected graph:\n");

    for (i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);

        if (u < 0 || u >= n || v < 0 || v >= n) {
            printf("Invalid edge. Enter vertices between 0 and %d.\n", n - 1);
            return 1;
        }

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    if (start < 0 || start >= n) {
        printf("Invalid starting vertex.\n");
        return 1;
    }

    do {
        printf("\n--- Graph Traversal Menu ---\n");
        printf("1. BFS\n");
        printf("2. DFS\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bfs(start);
                break;

            case 2:
                dfs(start);
                break;

            case 3:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 3);

    return 0;
}
