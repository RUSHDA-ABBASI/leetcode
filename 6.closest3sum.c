#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), compare);

    int closestSum = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < numsSize - 2; i++) {
        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (abs(target - sum) < abs(target - closestSum)) {
                closestSum = sum;
            }

            if (sum < target)
                left++;
            else if (sum > target)
                right--;
            else
                return sum; // exact match
        }
    }

    return closestSum;
}

int main() {
    int nums[] = {-1, 2, 1, -4};
    int target = 1;
    int n = sizeof(nums) / sizeof(nums[0]);

    printf("Closest Sum = %d\n", threeSumClosest(nums, n, target));
    return 0;
}
