#include <stdio.h>
#include <stdbool.h>

bool searchMatrix(int matrix[][4], int m, int n, int target) {
    int left = 0, right = m * n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int midValue = matrix[mid / n][mid % n];

        if (midValue == target)
            return true;
        else if (midValue < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;
}

int main() {
    int matrix[3][4] = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target;

    printf("Enter target value: ");
    scanf("%d", &target);

    if (searchMatrix(matrix, 3, 4, target))
        printf("Target %d found in matrix.\n", target);
    else
        printf("Target %d not found in matrix.\n", target);

    return 0;
}
