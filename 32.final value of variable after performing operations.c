#include <stdio.h>
#include <string.h>

int finalValueAfterOperations(char **operations, int operationsSize) {
    int X = 0;
    for (int i = 0; i < operationsSize; i++) {
        // Check the middle character to decide
        if (operations[i][1] == '+') {
            X++;
        } else {
            X--;
        }
    }
    return X;
}

int main(void) {
    int n;
    scanf("%d", &n);

    // Array of pointers to store strings
    char ops_storage[n][4];     // each operation is 3 chars + '\0'
    char *operations[n];

    for (int i = 0; i < n; i++) {
        scanf("%s", ops_storage[i]);  // read each operation
        operations[i] = ops_storage[i];
    }

    int result = finalValueAfterOperations(operations, n);
    printf("%d\n", result);

    return 0;
}
