#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* defangIPaddr(char* address) {
    int len = strlen(address);
    int dotCount = 0;

    // Count how many dots in the address
    for (int i = 0; i < len; i++) {
        if (address[i] == '.') {
            dotCount++;
        }
    }

    // Each '.' becomes "[.]" ? 3 chars instead of 1 ? +2 extra chars per dot
    int newLen = len + 2 * dotCount;

    // Allocate memory for the new string (+1 for '\0')
    char *res = (char *)malloc((newLen + 1) * sizeof(char));
    if (res == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    int j = 0; // index for res

    for (int i = 0; i < len; i++) {
        if (address[i] == '.') {
            res[j++] = '[';
            res[j++] = '.';
            res[j++] = ']';
        } else {
            res[j++] = address[i];
        }
    }

    res[j] = '\0'; // null terminate
    return res;
}

int main() {
    char address[50];

    printf("Enter a valid IPv4 address: ");
    scanf("%49s", address);   // read string (no spaces)

    char *defanged = defangIPaddr(address);

    printf("Defanged IP address: %s\n", defanged);

    // Free the memory allocated inside defangIPaddr
    free(defanged);

    return 0;
}
