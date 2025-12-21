#include <stdio.h>
#include <stdbool.h>

int main() {
    int candies[] = {2, 3, 5, 1, 3};
    int extraCandies = 3;
    int n = 5;
    int max = candies[0];

    // Find maximum candies
    for (int i = 1; i < n; i++) {
        if (candies[i] > max) {
            max = candies[i];
        }
    }

    // Check and print result
    for (int i = 0; i < n; i++) {
        if (candies[i] + extraCandies >= max)
            printf("true ");
        else
            printf("false ");
    }

    return 0;
}
