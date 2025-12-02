#include <stdio.h>

int reverseDegree(char s[]) {
    int sum = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        int weight = 26 - (s[i] - 'a');  // reversed alphabet weight
        sum += weight * (i + 1);         // index is 1-based
    }

    return sum;
}

int main() {
    char s[100];
    scanf("%s", s);

    printf("%d\n", reverseDegree(s));
    return 0;
}
