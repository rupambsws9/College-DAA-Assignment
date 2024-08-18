/*Create 3*4 matrix that takes input from user(rows ans cols also take from user)
and print the formatted output*/
#include <stdio.h>

int main() {
    int matrix[3][4];
    int i, j,n,k;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &k);

    printf("Enter elements of the 3x4 matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < k; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\t \nFormatted Output: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < k; j++) {
            printf("%5d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}