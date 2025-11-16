#include <stdio.h>

int searchInsert(int nums[], int n, int target) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left)/2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    // target not found, left is the insert position
    return left;
}

int main() {
    int n, target;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int nums[1000];  // assume max 1000 elements
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Enter target: ");
    scanf("%d", &target);

    int index = searchInsert(nums, n, target);
    printf("Result: %d\n", index);

    return 0;
}
