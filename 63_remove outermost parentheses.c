#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    char result[1000];
    int balance = 0;
    int i, j = 0;

    printf("Enter parentheses string: ");
    scanf("%s", s);   // input without spaces

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            if (balance > 0) {
                result[j++] = s[i];
            }
            balance++;
        } else if (s[i] == ')') {
            balance--;
            if (balance > 0) {
                result[j++] = s[i];
            }
        }
    }

    result[j] = '\0';

    printf("Result: %s\n", result);

    return 0;
}
