#include <stdio.h>
#include <stdbool.h>

int countConsistentStrings(char *allowed, char words[][20], int wordsSize) {
    bool allowedChars[26] = {false};

    // Store allowed characters
    for (int i = 0; allowed[i] != '\0'; i++) {
        allowedChars[allowed[i] - 'a'] = true;
    }

    int count = 0;

    // Check each word
    for (int i = 0; i < wordsSize; i++) {
        bool consistent = true;

        for (int j = 0; words[i][j] != '\0'; j++) {
            if (!allowedChars[words[i][j] - 'a']) {
                consistent = false;
                break;
            }
        }

        if (consistent) {
            count++;
        }
    }

    return count;
}

int main() {
    char allowed[] = "ab";
    char words[][20] = {"ad", "bd", "aaab", "baa", "badab"};
    int wordsSize = 5;

    int result = countConsistentStrings(allowed, words, wordsSize);

    printf("Number of consistent strings: %d\n", result);

    return 0;
}
