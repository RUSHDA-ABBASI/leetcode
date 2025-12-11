#include <stdio.h>

int maxOr;
int countAns;

void dfs(int* nums, int n, int index, int currOR) {
    if (index == n) {
        if (currOR == maxOr && currOR != 0) {
            countAns++;
        }
        return;
    }

    // include nums[index]
    dfs(nums, n, index + 1, currOR | nums[index]);

    // exclude nums[index]
    dfs(nums, n, index + 1, currOR);
}

int main() {
    int nums[] = {3, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    maxOr = 0;
    countAns = 0;

    // calculate maximum OR
    for (int i = 0; i < n; i++) {
        maxOr |= nums[i];
    }

    dfs(nums, n, 0, 0);

    printf("Number of subsets with max OR = %d\n", countAns);

    return 0;
}
