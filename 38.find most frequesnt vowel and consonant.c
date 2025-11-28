#include <stdio.h>
#include <string.h>

// Function to compute the required sum
int maxVowelConsonantSum(char* s) {
    int freq[26] = {0};

    // Count frequency of each letter
    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];
        if (ch >= 'a' && ch <= 'z') {    // safety check
            freq[ch - 'a']++;
        }
    }

    int maxVowelFreq = 0;
    int maxConsonantFreq = 0;

    for (int i = 0; i < 26; i++) {
        int count = freq[i];
        if (count == 0) continue;

        char ch = 'a' + i;
        // Check vowel
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            if (count > maxVowelFreq) {
                maxVowelFreq = count;
            }
        } else { // consonant
            if (count > maxConsonantFreq) {
                maxConsonantFreq = count;
            }
        }
    }

    return maxVowelFreq + maxConsonantFreq;
}

int main(void) {
    char s[100005];    // adjust size as needed

    printf("Enter a lowercase string: ");
    scanf("%100000s", s);  // reads up to first whitespace

    int result = maxVowelConsonantSum(s);
    printf("Sum of max vowel and consonant frequencies: %d\n", result);

    return 0;
}
