#include <stdio.h>

void generate(char* s, int idx, int n) {
    if (idx == n) {
        s[idx] = '\0';
        printf("%s\n", s);
        return;
    }

    // Option 1: always allowed
    s[idx] = '1';
    generate(s, idx + 1, n);

    // Option 2: '0' allowed only if previous is '1'
    if (idx == 0 || s[idx - 1] == '1') {
        s[idx] = '0';
        generate(s, idx + 1, n);
    }
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    char s[n + 1];
    generate(s, 0, n);

    return 0;
}
