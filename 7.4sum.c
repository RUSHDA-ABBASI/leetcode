#include <stdio.h>
#include <stdlib.h>

// comparator for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);

    int capacity = 1000;
    int** result = (int **)malloc(capacity * sizeof(int *));
    *returnColumnSizes = (int *)malloc(capacity * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < numsSize - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int left = j + 1;
            int right = numsSize - 1;

            while (left < right) {
                long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];

                if (sum == target) {
                    int *quad = (int *)malloc(4 * sizeof(int));
                    quad[0] = nums[i];
                    quad[1] = nums[j];
                    quad[2] = nums[left];
                    quad[3] = nums[right];

                    result[*returnSize] = quad;
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;

                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                } 
                else if (sum < target)
                    left++;
                else
                    right--;
            }
        }
    }

    return result;
}

int main() {
    int nums[] = {1, 0, -1, 0, -2, 2};
    int target = 0;
    int n = sizeof(nums) / sizeof(nums[0]);

    int returnSize;
    int *returnColumnSizes;
    int **res = fourSum(nums, n, target, &returnSize, &returnColumnSizes);

    printf("Quadruplets:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < 4; j++) {
            printf("%d", res[i][j]);
            if (j < 3) printf(", ");
        }
        printf("]\n");
    }

    return 0;
}
