#include <stdio.h>

int main() {
    int n = 4;
    int grid[4][4] = {
        {9, 9, 8, 1},
        {5, 6, 2, 6},
        {8, 2, 6, 4},
        {6, 2, 2, 2}
    };

    int size = n - 2;
    int maxLocal[size][size];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int max = grid[i][j];

            for (int r = i; r < i + 3; r++) {
                for (int c = j; c < j + 3; c++) {
                    if (grid[r][c] > max)
                        max = grid[r][c];
                }
            }
            maxLocal[i][j] = max;
        }
    }

    // Print result
    printf("Max Local Matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", maxLocal[i][j]);
        }
        printf("\n");
    }

    return 0;
}
