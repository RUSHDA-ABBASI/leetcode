#include <stdio.h>
#include <stdlib.h>

int findPermutationDifference(char* s, char* t) {
    int pos[256];
    int i = 0, sum = 0;

    while (s[i] != '\0') {
        pos[(unsigned char)s[i]] = i;
        i++;
    }

    i = 0;
    while (t[i] != '\0') {
        sum += abs(pos[(unsigned char)t[i]] - i);
        i++;
    }

    return sum;
}

int main() {
    char s[100], t[100];

    printf("Enter string s: ");
    scanf("%s", s);

    printf("Enter string t: ");
    scanf("%s", t);

    int result = findPermutationDifference(s, t);
    printf("Permutation Difference: %d\n", result);

    return 0;
}
