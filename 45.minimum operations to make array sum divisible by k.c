#include <stdio.h>

int main() {
    int nums[] = {3, 9, 7};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 5;

    long long sum = 0;

    for(int i = 0; i < numsSize; i++){
        sum += nums[i];
    }

    int operations = sum % k;

    printf("Minimum operations = %d\n", operations);

    return 0;
}
