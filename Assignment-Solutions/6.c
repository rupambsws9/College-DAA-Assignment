//Adjancy matrix represtation in c 

#include <stdio.h>

int main() {
    int a[50][50], i, j, n, k, l, e;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }
    printf("Enter the number of edges: ");
    scanf("%d", &e);
    for (i = 0; i < e; i++) {
        printf("Enter the edge (format: node1 node2): ");
        scanf("%d%d", &j, &l);
        a[j][l] = 1;
        a[l][j] = 1;
    }
    printf("The graph is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf(" %d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}