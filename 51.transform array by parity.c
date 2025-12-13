#include <stdio.h>

int main() {
    int nums[] = {4, 3, 2, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    int zeroCount = 0, oneCount = 0;

    // Replace even with 0, odd with 1
    for (int i = 0; i < n; i++) {
        if (nums[i] % 2 == 0)
            zeroCount++;
        else
            oneCount++;
    }

    // Sort result
    for (int i = 0; i < zeroCount; i++)
        nums[i] = 0;

    for (int i = zeroCount; i < n; i++)
        nums[i] = 1;

    // Print output
    printf("Output: ");
    for (int i = 0; i < n; i++)
        printf("%d ", nums[i]);

    return 0;
}
