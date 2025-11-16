#include <stdio.h>

/**
 * Merges two sorted arrays:
 *  - nums1: size m + n; first m elements are valid, last n are extra space
 *  - nums2: size n; all n elements are valid
 *
 * After this function, nums1 will contain all m + n elements in sorted order.
 */
void mergeSortedArrays(int* nums1, int m, int* nums2, int n) {
    int i = m - 1;         // Index of last valid element in nums1
    int j = n - 1;         // Index of last element in nums2
    int k = m + n - 1;     // Index of last position in nums1 (full length)

    // Merge from the back to avoid overwriting elements in nums1
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // If any elements remain in nums2, copy them.
    // If elements remain in nums1, they're already in the correct place.
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

/******** Example usage for dev / local testing ********/
int main(void) {
    int nums1[10] = {1, 2, 3, 0, 0, 0};  // capacity m + n (here 6), we declare bigger (10) just to be safe
    int nums2[] = {2, 5, 6};

    int m = 3; // valid elements in nums1
    int n = 3; // elements in nums2

    mergeSortedArrays(nums1, m, nums2, n);

    // Print result: nums1 should be [1,2,2,3,5,6]
    printf("Merged array: ");
    for (int i = 0; i < m + n; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    return 0;
}
