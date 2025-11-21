#include <stdio.h>
#include <stdlib.h>

int* buildArray(int* nums, int numsSize, int* returnSize) {
    int* ans = (int*)malloc(numsSize * sizeof(int));
    if (ans == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    for (int i = 0; i < numsSize; i++) {
        ans[i] = nums[ nums[i] ];
    }

    *returnSize = numsSize;
    return ans;
}

int main() {
    // Example: nums = [0, 2, 1, 5, 3, 4]
    int nums[] = {0, 2, 1, 5, 3, 4};
    int n = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* ans = buildArray(nums, n, &returnSize);

    if (ans == NULL) {
        return 1; // allocation error
    }

    printf("Result array: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", ans[i]);
        if (i < returnSize - 1) printf(", ");
    }
    printf("]\n");

    // Free allocated memory
    free(ans);

    return 0;
}
