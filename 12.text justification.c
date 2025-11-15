#include <stdio.h>
#include <string.h>

#define MAX 100
#define MAX_WORD_LEN 50

int main() {
    char words[MAX][MAX_WORD_LEN];
    int wordCount, maxWidth;

    printf("Enter number of words: ");
    scanf("%d", &wordCount);

    printf("Enter words:\n");
    for (int i = 0; i < wordCount; i++) {
        scanf("%s", words[i]);
    }

    printf("Enter max width: ");
    scanf("%d", &maxWidth);

    int i = 0;
    while (i < wordCount) {
        int lineLen = strlen(words[i]);
        int last = i + 1;

        // Greedy fit words in current line
        while (last < wordCount && lineLen + 1 + strlen(words[last]) <= maxWidth) {
            lineLen += 1 + strlen(words[last]);
            last++;
        }

        int numWords = last - i;
        int numSpaces = maxWidth - (lineLen - (numWords - 1));

        char line[200] = "";
        
        // Last line or one word -> left justified
        if (last == wordCount || numWords == 1) {
            for (int j = i; j < last; j++) {
                strcat(line, words[j]);
                if (j < last - 1) strcat(line, " ");
            }
            int spacesLeft = maxWidth - strlen(line);
            for (int s = 0; s < spacesLeft; s++) strcat(line, " ");
        } else {
            int spaceEach = numSpaces / (numWords - 1);
            int extra = numSpaces % (numWords - 1);
            
            for (int j = i; j < last; j++) {
                strcat(line, words[j]);
                if (j < last - 1) {
                    int spaces = spaceEach + (extra-- > 0 ? 1 : 0);
                    for (int s = 0; s < spaces; s++) strcat(line, " ");
                }
            }
        }

        printf("\"%s\"\n", line);
        i = last;
    }

    return 0;
}
