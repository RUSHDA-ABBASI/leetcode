#include <stdio.h>

int main() {
    int n;
    printf("Enter number of digits: ");
    scanf("%d", &n);

    int digits[n];
    printf("Enter the digits (space separated): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &digits[i]);
    }

    // Perform plus one
    int carry = 1;
    for (int i = n - 1; i >= 0; i--) {
        int sum = digits[i] + carry;
        digits[i] = sum % 10;
        carry = sum / 10;
    }

    printf("Result: ");
    if (carry) printf("%d ", carry);  // If carry remains, print it first
    for (int i = 0; i < n; i++) {
        printf("%d ", digits[i]);
    }
    printf("\n");

    return 0;
}
