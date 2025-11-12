#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to find unique triplets that sum to zero
void threeSum(int *nums, int numsSize) {
    if (numsSize < 3) {
        printf("No triplets possible.\n");
        return;
    }

    // Sort the array first
    qsort(nums, numsSize, sizeof(int), compare);

    printf("Unique triplets that sum to 0 are:\n");

    for (int i = 0; i < numsSize - 2; i++) {
        // Skip duplicate elements for i
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                printf("[%d, %d, %d]\n", nums[i], nums[left], nums[right]);

                // Skip duplicates for left and right
                while (left < right && nums[left] == nums[left + 1])
                    left++;
                while (left < right && nums[right] == nums[right - 1])
                    right--;

                left++;
                right--;
            } else if (sum < 0) {
                left++; // Need a bigger sum
            } else {
                right--; // Need a smaller sum
            }
        }
    }
}

int main() {
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int n = sizeof(nums) / sizeof(nums[0]);

    threeSum(nums, n);

    return 0;
}
