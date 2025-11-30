#include <stdio.h>

int minPartitions(char * n){
    int maxDigit = 0;
    for (int i = 0; n[i] != '\0'; i++) {
        int digit = n[i] - '0';      // convert char '0'..'9' ? int 0..9
        if (digit > maxDigit) {
            maxDigit = digit;
        }
    }
    return maxDigit;
}

int main() {
    char n[100005];  // buffer for the input number as string
    printf("Enter n: ");
    scanf("%100000s", n);  // read as string (no spaces)

    int result = minPartitions(n);
    printf("Minimum deci-binary numbers needed: %d\n", result);

    return 0;
}
