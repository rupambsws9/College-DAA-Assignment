/* KNAPSACK PROBLEM in c */

#include <stdio.h>
struct knap {
    int profit;
    int size;
};
int main() {
    int n, i, j, k = 0;
    float temp, temp1, s;
    float x[20];
    printf("How many elements? \n");
    scanf("%d", &n);
    struct knap a[n], c[n];
    for (i = 0; i < n; i++) {
        printf("Enter Profit & Size of element #%d\n", i + 1);
        scanf("%d%d", &a[i].profit, &a[i].size);
    }
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if ((float)a[j].profit / a[j].size < (float)a[j + 1].profit / a[j + 1].size) {
                temp = a[j].profit;
                a[j].profit = a[j + 1].profit;
                a[j + 1].profit = temp;
                temp1 = a[j].size;
                a[j].size = a[j + 1].size;
                a[j + 1].size = temp1;
            }
        }
    }
    for (i = 0; i < n; i++) {
        c[k].profit = a[i].profit;
        c[k].size = a[i].size;
        k++;
    }
    printf("\nProfit and Size in decreasing P/S ratio:\n");
    for (i = 0; i < n; i++) {
        printf("Profit = %d, Size = %d\n", c[i].profit, c[i].size);
    }
    printf("\nEnter the size of the bag: ");
    scanf("%f", &s);
    for (i = 0; i < n; i++) {
        x[i] = 0.0;
    }
    float U = s;  
    float P = 0.0; 
    for (i = 0; i < n; i++) {
        if (c[i].size <= U) {
            x[i] = 1.0;
            printf("Fraction taken of element #%d = %f\n", i + 1, x[i]);
            U = U - c[i].size;
            printf("Remaining Size of sack after filling with element #%d: %f\n", i + 1, U);
            P = P + c[i].profit;
            printf("Current Profit after filling sack with element #%d: %f\n", i + 1, P);
        } else {
            float m = U / (float)c[i].size;
            x[i] = m;
            printf("Fraction taken of element #%d = %f\n", i + 1, x[i]);
            P = P + (x[i] * c[i].profit);
            break;
        }
    }
    printf("\nMax Profit = %f\n", P);
    return 0;
}