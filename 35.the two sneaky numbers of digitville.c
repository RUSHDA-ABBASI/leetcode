#include <stdio.h>
#include <stdlib.h>

// Function to find two duplicate numbers
int* findTwoDuplicates(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    int idx = 0;

    for (int i = 0; i < numsSize; i++) {
        int val = nums[i];
        if (val < 0) val = -val;  // make sure it's positive

        if (nums[val] >= 0) {
            // first time: mark index val as visited
            nums[val] = -nums[val];
        } else {
            // second time: this is a duplicate
            result[idx++] = val;
            if (idx == 2) break;  // we only need two
        }
    }

    *returnSize = 2;
    return result;
}

int main() {
    int nums[] = {0, 1, 1, 0};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int returnSize;
    int* ans = findTwoDuplicates(nums, numsSize, &returnSize);

    printf("Duplicates are: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    free(ans);
    return 0;
}
