#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *longestCommonPrefix(char **strs, int strsSize) {
    if (strsSize == 0) return "";
    
    char *prefix = strs[0];
    int prefixLen = strlen(prefix);

    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        while (j < prefixLen && strs[i][j] == prefix[j]) {
            j++;
        }
        prefixLen = j;
        if (prefixLen == 0) return "";
    }

    char *result = (char *)malloc(prefixLen + 1);
    strncpy(result, prefix, prefixLen);
    result[prefixLen] = '\0';
    return result;
}

int main() {
    int n;
    printf("Enter number of strings: ");
    scanf("%d", &n);
    
    char **strs = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        strs[i] = (char *)malloc(100 * sizeof(char));
        printf("Enter string %d: ", i + 1);
        scanf("%s", strs[i]);
    }

    char *prefix = longestCommonPrefix(strs, n);
    printf("\nLongest Common Prefix: %s\n", prefix);

    // Free memory
    for (int i = 0; i < n; i++) {
        free(strs[i]);
    }
    free(strs);
    free(prefix);

    return 0;
}
