/* WAP in c that creates a function to find the sortest pathfrom a source vertex to all other vertices
using dijkstra's algorithm */
#include <stdio.h>
#include <limits.h>
#define MAX 100
#define INFINITY 100
void dijkstra(int graph[MAX][MAX], int n, int source);
int main() {
    int graph[MAX][MAX], n, source;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("\n\tEnter the adjacency matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j) {
                graph[i][j] = INFINITY;  // No direct path between the nodes
            }
        }
    }
    printf("Enter the source vertex (starting from 0): ");
    scanf("%d", &source);
    dijkstra(graph, n, source);
    return 0;
}
void dijkstra(int graph[MAX][MAX], int n, int source) {
    int dist[MAX], visited[MAX], pred[MAX];
    // Initialize distance, predecessor, and visited arrays
    for (int i = 0; i < n; i++) {
        dist[i] = INFINITY;
        visited[i] = 0;
        pred[i] = -1;
    }
    // Distance from source to itself is always 0
    dist[source] = 0;
    // Find the shortest path for all vertices
    for (int count = 0; count < n - 1; count++) {
        int min = INFINITY, u;
        // Find the vertex with the minimum distance from the source
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] <= min) {
                min = dist[i];
                u = i;
            }
        }
        // Mark the vertex as visited
        visited[u] = 1;
        // Update the distance value of the adjacent vertices of the picked vertex
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INFINITY && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                pred[v] = u;
            }
        }
    }
    // Print the results
    printf("\nVertex\tDistance from Source\tPath\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t", i, dist[i]);
        if (dist[i] == INFINITY) {
            printf("No path\n");
        } else {
            printf("%d", i);
            int j = i;
            while (pred[j] != -1) {
                printf(" <- %d", pred[j]);
                j = pred[j];
            }
            printf("\n");
        }
    }
}