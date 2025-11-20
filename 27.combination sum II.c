#include <stdio.h>
#include <stdlib.h>

int cmpInt(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void backtrack(int* candidates, int candidatesSize, int target,
               int start, int* buffer, int bufLen,
               int*** res, int* returnSize, int** returnColumnSizes, int* capacity) {
    if (target == 0) {
        // Expand capacity if needed
        if (*returnSize >= *capacity) {
            *capacity *= 2;
            *res = (int**)realloc(*res, (*capacity) * sizeof(int*));
            *returnColumnSizes = (int*)realloc(*returnColumnSizes, (*capacity) * sizeof(int));
        }

        // Copy current combination
        (*res)[*returnSize] = (int*)malloc(bufLen * sizeof(int));
        for (int i = 0; i < bufLen; i++) {
            (*res)[*returnSize][i] = buffer[i];
        }
        (*returnColumnSizes)[*returnSize] = bufLen;
        (*returnSize)++;
        return;
    }

    for (int i = start; i < candidatesSize; i++) {
        // Skip duplicates at same recursion depth
        if (i > start && candidates[i] == candidates[i - 1]) {
            continue;
        }

        if (candidates[i] > target) {
            break; // No need to try further (sorted)
        }

        buffer[bufLen] = candidates[i];
        backtrack(candidates, candidatesSize, target - candidates[i],
                  i + 1, buffer, bufLen + 1, res, returnSize, returnColumnSizes, capacity);
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target, 
                      int* returnSize, int** returnColumnSizes) {
    // Sort the array first
    qsort(candidates, candidatesSize, sizeof(int), cmpInt);

    int capacity = 200; // initial capacity
    int** res = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));
    *returnSize = 0;

    int* buffer = (int*)malloc(candidatesSize * sizeof(int));

    backtrack(candidates, candidatesSize, target, 0, buffer, 0,
              &res, returnSize, returnColumnSizes, &capacity);

    free(buffer);
    return res;
}

int main() {
    int candidates[] = {10, 1, 2, 7, 6, 1, 5};
    int candidatesSize = sizeof(candidates) / sizeof(candidates[0]);
    int target = 8;

    int returnSize;
    int* returnColumnSizes;
    int** result = combinationSum2(candidates, candidatesSize, target,
                                   &returnSize, &returnColumnSizes);

    printf("Combinations that sum to %d:\n", target);
    for (int i = 0; i < returnSize; i++) {
        printf("[ ");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("]\n");
        free(result[i]);
    }

    free(result);
    free(returnColumnSizes);

    return 0;
}
