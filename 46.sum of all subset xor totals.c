#include <stdio.h>

int subsetXORSum(int nums[], int n){
    int OR = 0;
    for(int i = 0; i < n; i++){
        OR |= nums[i];
    }
    return OR * (1 << (n - 1));
}

int main()
{
    int nums[] = {1, 3};
    int n = sizeof(nums) / sizeof(nums[0]);

    int result = subsetXORSum(nums, n);
    printf("Sum of all subset XOR = %d\n", result);

    return 0;
}
