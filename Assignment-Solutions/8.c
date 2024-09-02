//c program to implementation of travelling salesman problem 
#include <stdio.h>
#include <limits.h>
#define MAX_CITIES 10
int n;
int cost[MAX_CITIES][MAX_CITIES];
int visited[MAX_CITIES];
int minCost = INT_MAX;
int path[MAX_CITIES + 1];
int bestPath[MAX_CITIES + 1];
void tsp(int city, int count, int costSoFar, int start) {
    if (count == n && cost[city][start]) {
        if (costSoFar + cost[city][start] < minCost) {
            minCost = costSoFar + cost[city][start];
            for (int i = 0; i < n; i++) {
                bestPath[i] = path[i];
            }
            bestPath[n] = start;
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i] && cost[city][i]) {
            visited[i] = 1;
            path[count] = i;
            tsp(i, count + 1, costSoFar + cost[city][i], start);
            visited[i] = 0;
        }
    }
}
int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter costs for row %d (space-separated): ", i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    visited[0] = 1;
    path[0] = 0;
    tsp(0, 1, 0, 0);
    printf("Path taken:\n");
    for (int i = 0; i <= n; i++) {
        printf("%d ", bestPath[i] + 1); // Displaying path starting from 1
    }
    printf("\n");
    printf("Minimum cost: %d\n", minCost);
    return 0;
}