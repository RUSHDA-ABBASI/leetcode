#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* interpret(const char* command) {
    int n = strlen(command);
    char* res = malloc(n + 1);
    int i = 0, j = 0;

    while (command[i] != '\0') {
        if (command[i] == 'G') {
            res[j++] = 'G';
            i++;
        }
        else if (command[i] == '(' && command[i+1] == ')') {
            res[j++] = 'o';
            i += 2;
        }
        else {  // "(al)"
            res[j++] = 'a';
            res[j++] = 'l';
            i += 4;
        }
    }

    res[j] = '\0';
    return res;
}

int main() {
    char command[100];
    printf("Enter command: ");
    scanf("%s", command);

    char* result = interpret(command);
    printf("Output: %s\n", result);

    free(result);
    return 0;
}
