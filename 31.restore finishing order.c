#include <stdio.h>
#include <stdlib.h>

// Function to recover friends' finishing order
int* recoverOrder(int* order, int orderSize, int* friends, int friendsSize, int* returnSize) {
    int n = orderSize;

    // Step 1: mark all friends
    int* isFriend = (int*)calloc(n + 1, sizeof(int));
    if (!isFriend) {
        *returnSize = 0;
        return NULL;
    }
    for (int i = 0; i < friendsSize; i++) {
        isFriend[friends[i]] = 1;
    }

    // Step 2: allocate result array
    int* result = (int*)malloc(friendsSize * sizeof(int));
    if (!result) {
        free(isFriend);
        *returnSize = 0;
        return NULL;
    }

    // Step 3: scan order and collect friends
    int idx = 0;
    for (int i = 0; i < orderSize; i++) {
        if (isFriend[order[i]]) {
            result[idx++] = order[i];
        }
    }

    *returnSize = idx;
    free(isFriend);
    return result;
}

int main() {
    // Example input
    int order[] = {3, 1, 2, 5, 4};
    int friends[] = {1, 3, 4};
    int orderSize = sizeof(order) / sizeof(order[0]);
    int friendsSize = sizeof(friends) / sizeof(friends[0]);

    int returnSize;
    int* result = recoverOrder(order, orderSize, friends, friendsSize, &returnSize);

    if (!result) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Print the result
    printf("Friends' finishing order: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i + 1 < returnSize) printf(", ");
    }
    printf("]\n");

    free(result);
    return 0;
}
