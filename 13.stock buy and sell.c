#include <stdio.h>

int maxProfit(int prices[], int n) {
    if (n == 0) {
        return 0;
    }

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < n; i++) {
        int profitToday = prices[i] - minPrice;

        if (profitToday > maxProfit) {
            maxProfit = profitToday;
        }

        if (prices[i] < minPrice) {
            minPrice = prices[i];
        }
    }

    return maxProfit;
}

int main() {
    int n;
    printf("Enter number of days: ");
    scanf("%d", &n);

    int prices[1000];  // assume max 1000 days
    printf("Enter prices for %d days: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }

    int result = maxProfit(prices, n);
    printf("Maximum profit: %d\n", result);

    return 0;
}
