#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int k = 0;  // counter for elements not equal to val

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];  // copy valid elements to front
            k++;
        }
    }

    return k;  // number of elements not equal to val
}

int main() {
    int nums[] = {3, 2, 2, 3};
    int val = 3;
    int size = sizeof(nums) / sizeof(nums[0]);

    int k = removeElement(nums, size, val);

    printf("Number of elements not equal to %d: %d\n", val, k);
    printf("Array after removal: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }

    printf("\n");
    return 0;
}
