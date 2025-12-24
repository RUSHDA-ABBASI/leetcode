#include <stdio.h>
#include <stdlib.h>

int main() {
    int nums[] = {10, 4, 8, 3};
    int n = sizeof(nums) / sizeof(nums[0]);
    int totalSum = 0, leftSum = 0;

    // Calculate total sum
    for (int i = 0; i < n; i++) {
        totalSum += nums[i];
    }

    int answer[n];

    for (int i = 0; i < n; i++) {
        int rightSum = totalSum - leftSum - nums[i];
        answer[i] = abs(leftSum - rightSum);
        leftSum += nums[i];
    }

    // Print result
    printf("Output: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", answer[i]);
    }

    return 0;
}
