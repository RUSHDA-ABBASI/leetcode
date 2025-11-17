#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void permuteUniqueHelper(int* nums, int numsSize, int* current, int currentSize, int* used,
                         int*** result, int* resultSize, int** colSizes, int* capacity) {
    if (currentSize == numsSize) {
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
        if (used[i]) continue;
        if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue; // skip duplicates

        used[i] = 1;
        current[currentSize] = nums[i];
        permuteUniqueHelper(nums, numsSize, current, currentSize + 1, used,
                            result, resultSize, colSizes, capacity);
        used[i] = 0; // backtrack
    }
}

int** permuteUniqueDev(int* nums, int numsSize, int* outResultSize, int** outColSizes) {
    int capacity = 128;
    int** result = (int**)malloc(capacity * sizeof(int*));
    int* colSizes = (int*)malloc(capacity * sizeof(int));
    *outResultSize = 0;

    int* current = (int*)malloc(numsSize * sizeof(int));
    int* used = (int*)calloc(numsSize, sizeof(int));

    qsort(nums, numsSize, sizeof(int), compareInt);

    permuteUniqueHelper(nums, numsSize, current, 0, used, &result, outResultSize, &colSizes, &capacity);

    free(current);
    free(used);
    *outColSizes = colSizes;
    return result;
}

/*** Example usage ***/
int main() {
    int nums[] = {1,1,2};
    int n = sizeof(nums)/sizeof(nums[0]);
    int resultSize;
    int* colSizes;
    int** permutations = permuteUniqueDev(nums, n, &resultSize, &colSizes);

    printf("Number of unique permutations: %d\n", resultSize);
    for (int i = 0; i < resultSize; i++) {
        printf("[ ");
        for (int j = 0; j < colSizes[i]; j++) {
            printf("%d ", permutations[i][j]);
        }
        printf("]\n");
        free(permutations[i]);
    }

    free(permutations);
    free(colSizes);

    return 0;
}
