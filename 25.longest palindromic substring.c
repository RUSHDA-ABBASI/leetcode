#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void expandAroundCenter(char *s, int left, int right, int *bestStart, int *bestLen) {
    int n = strlen(s);

    while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
    }

    int currLen = right - left - 1;
    int currStart = left + 1;

    if (currLen > *bestLen) {
        *bestLen = currLen;
        *bestStart = currStart;
    }
}

char * longestPalindrome(char * s) {
    int n = strlen(s);
    if (n == 0) return s;

    int bestStart = 0;
    int bestLen = 1;

    for (int i = 0; i < n; i++) {
        // Odd length
        expandAroundCenter(s, i, i, &bestStart, &bestLen);

        // Even length
        expandAroundCenter(s, i, i + 1, &bestStart, &bestLen);
    }

    char *res = (char *)malloc((bestLen + 1) * sizeof(char));
    if (!res) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    strncpy(res, s + bestStart, bestLen);
    res[bestLen] = '\0';

    return res;
}

int main() {
    char s[1001];   // constraints: length <= 1000

    printf("Enter a string: ");
    scanf("%1000s", s);   // read without spaces

    char *ans = longestPalindrome(s);

    printf("Longest palindromic substring: %s\n", ans);

    free(ans);  // free allocated memory

    return 0;
}
