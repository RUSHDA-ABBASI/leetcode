#include <stdio.h>

#define MAX 100

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int triangle[MAX][MAX];
    int n;

    printf("Enter number of rows in triangle: ");
    scanf("%d", &n);

    printf("Enter triangle elements row by row:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &triangle[i][j]);
        }
    }

    // Dynamic Programming (bottom-up)
    for (int row = n - 2; row >= 0; row--) {
        for (int col = 0; col <= row; col++) {
            triangle[row][col] += min(triangle[row + 1][col], triangle[row + 1][col + 1]);
        }
    }

    printf("Minimum path sum = %d\n", triangle[0][0]);
    return 0;
}
