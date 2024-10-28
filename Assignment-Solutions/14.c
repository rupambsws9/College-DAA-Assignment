/* JOB SEQUENCING WITH DEADLINE in c */

#include <stdio.h>
struct job {
    int profit;
    int deadline;
};
int main() {
    int i, j, profit = 0, n, k = 0, r, t, maxDeadline, p;
    struct job a[10], b[10];
    printf("Enter number of jobs: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter profit and deadline for job #%d: ", i + 1);
        scanf("%d %d", &a[i].profit, &a[i].deadline);
    }
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j].profit < a[j + 1].profit) {
                int temp = a[j].profit;
                a[j].profit = a[j + 1].profit;
                a[j + 1].profit = temp;
                int temp1 = a[j].deadline;
                a[j].deadline = a[j + 1].deadline;
                a[j + 1].deadline = temp1;
            }
        }
    }
    maxDeadline = -1;
    for (i = 0; i < n; i++) {
        if (a[i].deadline > maxDeadline) {
            maxDeadline = a[i].deadline;
        }
    }
    printf("Maximum deadline is: %d\n", maxDeadline);
    for (i = 0; i < maxDeadline; i++) {
        b[i].profit = -1;
        b[i].deadline = -1;
    }
    profit = 0;
    for (i = 0; i < n; i++) {
        for (r = a[i].deadline - 1; r >= 0; r--) {
            if (b[r].profit == -1) {
                b[r].profit = a[i].profit;
                b[r].deadline = a[i].deadline;
                profit += a[i].profit;
                break;
            }
        }
    }
    printf("\nOptimal job sequence is:\n");
    for (p = 0; p < maxDeadline; p++) {
        if (b[p].profit != -1) {
            printf("Job %d selected: Profit = %d, Deadline = %d\n", p + 1, b[p].profit, b[p].deadline);
        }
    }
    printf("\nMax Profit = %d\n", profit);
    return 0;
}