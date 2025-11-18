#include <stdio.h>

int value(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(char * s) {
    int total = 0;
    int i = 0;

    while (s[i] != '\0') {
        int curr = value(s[i]);
        int next = value(s[i + 1]);   // 0 if end of string

        if (curr < next) {
            total += (next - curr);
            i += 2;
        } else {
            total += curr;
            i++;
        }
    }

    return total;
}

int main() {
    char s[20];   // enough for typical Roman numerals

    printf("Enter a Roman numeral (e.g. III, IX, LVIII): ");
    scanf("%19s", s);   // read string safely

    int result = romanToInt(s);

    printf("Integer value: %d\n", result);

    return 0;
}
