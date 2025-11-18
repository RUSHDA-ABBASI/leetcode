#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// comparison function for qsort
int cmpInt(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

bool containsDuplicate(int* nums, int numsSize) {
    if (numsSize <= 1) return false;

    qsort(nums, numsSize, sizeof(int), cmpInt);

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
            return true;
        }
    }

    return false;
}

int main() {
    int nums[] = {1, 2, 3, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    bool result = containsDuplicate(nums, n);

    if (result) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
