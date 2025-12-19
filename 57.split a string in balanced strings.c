#include <stdio.h>

int balancedStringSplit(char s[]) {
    int count = 0;    // number of balanced substrings
    int balance = 0;  // tracks L and R balance

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'R')
            balance++;
        else if (s[i] == 'L')
            balance--;

        if (balance == 0)
            count++;
    }

    return count;
}

int main() {
    char s[100];

    printf("Enter a balanced string (L and R only): ");
    scanf("%s", s);

    int result = balancedStringSplit(s);
    printf("Maximum number of balanced substrings: %d\n", result);

    return 0;
}
