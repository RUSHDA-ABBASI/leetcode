#include <stdio.h>
#include <stdlib.h>

int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    int n = numsSize;
    int* ans = (int*)malloc(2 * n * sizeof(int));
    if (ans == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        ans[i] = nums[i];       // first half
        ans[i + n] = nums[i];   // second half
    }

    *returnSize = 2 * n;
    return ans;
}

int main() {
    // Example: nums = [1, 2, 1]
    int nums[] = {1, 2, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* ans = getConcatenation(nums, n, &returnSize);
    if (ans == NULL) {
        return 1; // allocation failed
    }

    printf("Result array: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", ans[i]);
        if (i < returnSize - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    free(ans);
    return 0;
}
