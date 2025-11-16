#include <stdio.h>
#include <stdlib.h>

int compareInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

/**
 * Backtracking helper.
 *
 * @param candidates         array of distinct candidate numbers
 * @param n                  number of candidates
 * @param target             remaining sum to achieve
 * @param startIndex         index to start picking candidates from
 * @param currentCombo       array holding current partial combination
 * @param currentSize        current size of currentCombo
 * @param result             pointer to array of int* for storing combinations
 * @param resultSize         pointer to current number of stored combinations
 * @param colSizes           pointer to array storing sizes of each combination
 * @param capacity           pointer to current capacity of result/colSizes arrays
 */
void backtrack(int* candidates, int n,
               int target,
               int startIndex,
               int* currentCombo, int currentSize,
               int*** result, int* resultSize,
               int** colSizes,
               int* capacity) {

    if (target == 0) {
        // Found a valid combination

        // Ensure we have enough room in result arrays
        if (*resultSize >= *capacity) {
            *capacity *= 2;
            *result = (int**)realloc(*result, (*capacity) * sizeof(int*));
            *colSizes = (int*)realloc(*colSizes, (*capacity) * sizeof(int));
        }

        // Copy current combination
        int* comboCopy = (int*)malloc(currentSize * sizeof(int));
        for (int i = 0; i < currentSize; i++) {
            comboCopy[i] = currentCombo[i];
        }

        (*result)[*resultSize] = comboCopy;
        (*colSizes)[*resultSize] = currentSize;
        (*resultSize)++;
        return;
    }

    if (target < 0) {
        // Overshoot; stop exploring this path
        return;
    }

    for (int i = startIndex; i < n; i++) {
        int value = candidates[i];

        // Choose this candidate
        currentCombo[currentSize] = value;

        // Because we can reuse the same number, we pass i again (not i+1)
        backtrack(candidates, n,
                  target - value,
                  i,
                  currentCombo, currentSize + 1,
                  result, resultSize, colSizes, capacity);
        // Backtrack: nothing to explicitly undo, we just overwrite currentCombo[currentSize]
        // on next iterations and recursion returns with reduced currentSize.
    }
}

/**
 * Public API-style function.
 */
int** combinationSumDev(int* candidates, int candidatesSize, int target,
                        int* outResultSize, int** outColSizes) {

    *outResultSize = 0;

    // Sort candidates so results are more predictable (and easier to debug)
    qsort(candidates, candidatesSize, sizeof(int), compareInt);

    int capacity = 128; // starting capacity for number of combinations
    int** result = (int**)malloc(capacity * sizeof(int*));
    int* colSizes = (int*)malloc(capacity * sizeof(int));

    // This is the current combination stack; we assume max length won't exceed target.
    // For safety in general code, you could allocate "target" size.
    int maxDepth = target; 
    int* currentCombo = (int*)malloc(maxDepth * sizeof(int));

    backtrack(candidates, candidatesSize,
              target,
              0,
              currentCombo, 0,
              &result, outResultSize, &colSizes,
              &capacity);

    free(currentCombo);
    *outColSizes = colSizes;
    return result;
}

/*** Example usage (for your own testing) ***/
int main(void) {
    int candidates[] = {2, 3, 6, 7};
    int n = sizeof(candidates) / sizeof(candidates[0]);
    int target = 7;

    int resultSize;
    int* colSizes;
    int** combinations = combinationSumDev(candidates, n, target, &resultSize, &colSizes);

    printf("Number of combinations = %d\n", resultSize);
    for (int i = 0; i < resultSize; i++) {
        printf("[ ");
        for (int j = 0; j < colSizes[i]; j++) {
            printf("%d ", combinations[i][j]);
        }
        printf("]\n");
        free(combinations[i]); // free each combination
    }

    free(combinations);
    free(colSizes);

    return 0;
}
