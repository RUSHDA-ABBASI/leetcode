#include <stdio.h>
#include <stdbool.h>

int numJewelsInStones(char* jewels, char* stones) {
    bool isJewel[128] = {false};

    // Mark jewels
    for (int i = 0; jewels[i] != '\0'; i++) {
        unsigned char ch = jewels[i];
        isJewel[ch] = true;
    }

    int count = 0;
    // Count jewels in stones
    for (int i = 0; stones[i] != '\0'; i++) {
        unsigned char ch = stones[i];
        if (isJewel[ch]) {
            count++;
        }
    }

    return count;
}

int main() {
    char jewels[101];
    char stones[101];

    printf("Enter jewels string: ");
    scanf("%100s", jewels);

    printf("Enter stones string: ");
    scanf("%100s", stones);

    int result = numJewelsInStones(jewels, stones);
    printf("Number of jewels in stones: %d\n", result);

    return 0;
}
