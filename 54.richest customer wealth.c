#include <stdio.h>

int main() {
    int m, n;
    int maxWealth = 0;

    printf("Enter number of customers: ");
    scanf("%d", &m);

    printf("Enter number of bank accounts per customer: ");
    scanf("%d", &n);

    int accounts[m][n];

    printf("Enter account values:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &accounts[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += accounts[i][j];
        }

        if (sum > maxWealth) {
            maxWealth = sum;
        }
    }

    printf("Richest customer wealth = %d\n", maxWealth);

    return 0;
}
