#include <stdio.h>

int main() {
    int nums[] = {2,5,1,3,4,7};
    int n = 3;
    int size = 2 * n;

    int result[size];
    int index = 0;

    for (int i = 0; i < n; i++) {
        result[index++] = nums[i];      // xi
        result[index++] = nums[i + n];  // yi
    }

    printf("Shuffled array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
