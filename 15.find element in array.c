#include <stdio.h>
#include <stdlib.h>

int binarySearchFirst(int* nums, int n, int target) {
    int left = 0, right = n - 1, result = -1;
    while (left <= right) {
        int mid = left + (right - left)/2;
        if (nums[mid] == target) {
            result = mid;
            right = mid - 1; // search left
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int binarySearchLast(int* nums, int n, int target) {
    int left = 0, right = n - 1, result = -1;
    while (left <= right) {
        int mid = left + (right - left)/2;
        if (nums[mid] == target) {
            result = mid;
            left = mid + 1; // search right
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int main() {
    int n, target;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int nums[1000]; // max size 1000
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Enter target: ");
    scanf("%d", &target);

    int start = binarySearchFirst(nums, n, target);
    int end = binarySearchLast(nums, n, target);

    printf("Result: [%d, %d]\n", start, end);

    return 0;
}
