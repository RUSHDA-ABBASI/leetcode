#include <stdio.h>
#include <stdlib.h>  // for abs()
#include <string.h>  // for strlen()

int scoreOfString(char* s) {
    int score = 0;
    int n = strlen(s);
    
    for (int i = 0; i < n - 1; i++) {
        score += abs(s[i] - s[i + 1]);
    }
    
    return score;
}

int main() {
    char s[1001];  // assuming max length 1000 (adjust if needed)

    printf("Enter a string: ");
    if (scanf("%1000s", s) != 1) {  // read a word (no spaces)
        printf("Error reading input.\n");
        return 1;
    }

    int result = scoreOfString(s);
    printf("Score of the string is: %d\n", result);

    return 0;
}
