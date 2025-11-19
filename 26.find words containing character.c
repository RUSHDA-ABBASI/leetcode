#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    printf("Enter number of words: ");
    scanf("%d", &n);

    // Allocate array of strings
    char words[100][101]; // max 100 words, each max length 100
    // (You can adjust sizes as needed)

    printf("Enter %d words:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%100s", words[i]);
    }

    char x;
    printf("Enter character x: ");
    scanf(" %c", &x);   // space before %c to skip newline

    int indices[100];   // to store indices that contain x
    int count = 0;

    // Find indices of words containing x
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; words[i][j] != '\0'; j++) {
            if (words[i][j] == x) {
                found = 1;
                break;
            }
        }
        if (found) {
            indices[count++] = i;
        }
    }

    // Print result
    printf("Indices of words containing '%c': ", x);
    if (count == 0) {
        printf("None\n");
    } else {
        for (int i = 0; i < count; i++) {
            printf("%d ", indices[i]);
        }
        printf("\n");
    }

    return 0;
}
