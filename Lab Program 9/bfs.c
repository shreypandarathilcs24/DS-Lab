#include <stdio.h>

int n;
int graph[10][10];
int visited[10];
int queue[10], front = 0, rear = -1;

void bfs(int start) {
    int i;
    visited[start] = 1;
    queue[++rear] = start;

    while (front <= rear) {
        int current = queue[front++]; // Get the front of the queue
        printf("%d ", current);

        for (i = 0; i < n; i++) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[++rear] = i; // Enqueue the vertex
            }
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize visited array to 0 (unvisited)
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    bfs(start);  // Perform BFS traversal starting from 'start' vertex

    return 0;
}