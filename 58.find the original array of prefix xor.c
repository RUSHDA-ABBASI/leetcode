#include <stdio.h>

int main() {
    int pref[] = {5, 2, 0, 3, 1};
    int n = sizeof(pref) / sizeof(pref[0]);
    int arr[n];

    arr[0] = pref[0];
    for (int i = 1; i < n; i++) {
        arr[i] = pref[i] ^ pref[i - 1];
    }

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
