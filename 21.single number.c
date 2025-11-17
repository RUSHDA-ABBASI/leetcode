#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
    int x = 0;
    for (int i = 0; i < numsSize; i++) {
        x ^= nums[i];
    }
    return x;
}

int main() {
    int nums[] = {2, 2, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    int result = singleNumber(nums, n);
    printf("The single number is: %d\n", result);

    return 0;
}
