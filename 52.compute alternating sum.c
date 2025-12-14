#include <stdio.h>

int alternatingSum(int nums[], int n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            sum += nums[i];
        else
            sum -= nums[i];
    }

    return sum;
}

int main() {
    int nums[] = {1, 3, 5, 7};
    int n = sizeof(nums) / sizeof(nums[0]);

    int result = alternatingSum(nums, n);
    printf("Alternating Sum = %d\n", result);

    return 0;
}
