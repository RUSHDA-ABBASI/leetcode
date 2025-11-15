#include <stdio.h>

// Function to search target in rotated sorted array
int search(int nums[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
            return mid; // found

        // Determine which half is sorted
        if (nums[left] <= nums[mid]) { // left half sorted
            if (nums[left] <= target && target < nums[mid])
                right = mid - 1; // search left half
            else
                left = mid + 1;  // search right half
        } else { // right half sorted
            if (nums[mid] < target && target <= nums[right])
                left = mid + 1;  // search right half
            else
                right = mid - 1; // search left half
        }
    }

    return -1; // target not found
}

int main() {
    int n, target;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int nums[1000]; // assume max size 1000
    printf("Enter %d array elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Enter target to search: ");
    scanf("%d", &target);

    int index = search(nums, n, target);
    if (index != -1)
        printf("Target found at index: %d\n", index);
    else
        printf("Target not found\n");

    return 0;
}
