#include <stdio.h>

int majorityElement(int* nums, int numsSize) {
    int candidate = nums[0];
    int count = 1;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == candidate) {
            count++;
        } else {
            count--;
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            }
        }
    }

    return candidate;
}

int main() {
    int nums[] = {3, 2, 3};
    int n = sizeof(nums) / sizeof(nums[0]);

    int result = majorityElement(nums, n);
    printf("The majority element is: %d\n", result);

    return 0;
}
