#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* minOperations(char* boxes, int* returnSize) {
    int n = strlen(boxes);
    *returnSize = n;

    int* answer = (int*)malloc(n * sizeof(int));
    int* leftMoves = (int*)calloc(n, sizeof(int));   // initialized to 0
    int* rightMoves = (int*)calloc(n, sizeof(int));  // initialized to 0

    // Left to right
    int balls_left = 0;
    if (boxes[0] == '1') balls_left = 1;
    leftMoves[0] = 0;

    for (int i = 1; i < n; i++) {
        leftMoves[i] = leftMoves[i - 1] + balls_left;
        if (boxes[i] == '1') {
            balls_left++;
        }
    }

    // Right to left
    int balls_right = 0;
    rightMoves[n - 1] = 0;
    if (boxes[n - 1] == '1') balls_right = 1;

    for (int i = n - 2; i >= 0; i--) {
        rightMoves[i] = rightMoves[i + 1] + balls_right;
        if (boxes[i] == '1') {
            balls_right++;
        }
    }

    // Final answer
    for (int i = 0; i < n; i++) {
        answer[i] = leftMoves[i] + rightMoves[i];
    }

    free(leftMoves);
    free(rightMoves);
    return answer;
}

int main() {
    char boxes[105];

    printf("Enter boxes string (e.g., 110): ");
    scanf("%s", boxes);

    int n;
    int* ans = minOperations(boxes, &n);

    printf("Output: [");
    for (int i = 0; i < n; i++) {
        printf("%d", ans[i]);
        if (i != n - 1) printf(", ");
    }
    printf("]\n");

    free(ans);
    return 0;
}
