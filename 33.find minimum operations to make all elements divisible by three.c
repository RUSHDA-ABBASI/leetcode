#include <stdio.h>

int minimumOperations(int* nums, int numsSize) {
    int ops = 0;
    for (int i = 0; i < numsSize; i++) {
        int rem = nums[i] % 3;
        if (rem != 0) {
            ops += 1;   // needs exactly 1 operation to become divisible by 3
        }
    }
    return ops;
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int nums[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int result = minimumOperations(nums, n);
    printf("Minimum operations to make all elements divisible by 3 = %d\n", result);

    return 0;
}
