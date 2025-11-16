#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Helper function to perform backtracking for permutations
 */
void permuteHelper(int* nums, int numsSize, int* current, int currentSize, int* used,
                   int*** result, int* resultSize, int** colSizes, int* capacity) {
    if (currentSize == numsSize) {
        // Found a valid permutation
        if (*resultSize >= *capacity) {
            *capacity *= 2;
            *result = (int**)realloc(*result, (*capacity) * sizeof(int*));
            *colSizes = (int*)realloc(*colSizes, (*capacity) * sizeof(int));
        }
        int* perm = (int*)malloc(numsSize * sizeof(int));
        memcpy(perm, current, numsSize * sizeof(int));
        (*result)[*resultSize] = perm;
        (*colSizes)[*resultSize] = numsSize;
        (*resultSize)++;
        return;
    }

    for (int i = 0; i < numsSize; i++) {
        if (!used[i]) {
            used[i] = 1;
            current[currentSize] = nums[i];
            permuteHelper(nums, numsSize, current, currentSize + 1, used,
                          result, resultSize, colSizes, capacity);
            used[i] = 0; // backtrack
        }
    }
}

/**
 * Public API-style function for Dev C++ usage
 */
int** permuteDev(int* nums, int numsSize, int* outResultSize, int** outColSizes) {
    int capacity = 128;
    int** result = (int**)malloc(capacity * sizeof(int*));
    int* colSizes = (int*)malloc(capacity * sizeof(int));
    *outResultSize = 0;

    int* current = (int*)malloc(numsSize * sizeof(int));
    int* used = (int*)calloc(numsSize, sizeof(int));

    permuteHelper(nums, numsSize, current, 0, used, &result, outResultSize, &colSizes, &capacity);

    free(current);
    free(used);
    *outColSizes = colSizes;
    return result;
}

/*** Example usage in Dev C++ ***/
int main() {
    int nums[] = {1, 2, 3};
    int n = sizeof(nums)/sizeof(nums[0]);
    int resultSize;
    int* colSizes;
    int** permutations = permuteDev(nums, n, &resultSize, &colSizes);

    printf("Number of permutations: %d\n", resultSize);
    for (int i = 0; i < resultSize; i++) {
        printf("[ ");
        for (int j = 0; j < colSizes[i]; j++) {
            printf("%d ", permutations[i][j]);
        }
        printf("]\n");
        free(permutations[i]); // free each permutation
    }

    free(permutations);
    free(colSizes);

    return 0;
}
