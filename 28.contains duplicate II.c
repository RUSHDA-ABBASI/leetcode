#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int key;           // value from array
    int index;         // last index where it appeared
    struct Node* next;
} Node;

#define TABLE_SIZE 10007   // good prime number for hashing

int hash(int key) {
    if (key < 0) key = -key;
    return key % TABLE_SIZE;
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    Node* table[TABLE_SIZE] = {0};

    for (int i = 0; i < numsSize; i++) {
        int h = hash(nums[i]);
        Node* curr = table[h];

        // search existing chain
        while (curr) {
            if (curr->key == nums[i]) {
                if (i - curr->index <= k) {
                    // free memory before return
                    for (int t = 0; t < TABLE_SIZE; t++) {
                        Node* p = table[t];
                        while (p) {
                            Node* temp = p->next;
                            free(p);
                            p = temp;
                        }
                    }
                    return true;
                }
                // update last index
                curr->index = i;
                break;
            }
            curr = curr->next;
        }

        // not found ? insert new node
        if (!curr) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->key = nums[i];
            newNode->index = i;
            newNode->next = table[h];
            table[h] = newNode;
        }
    }

    // free hash table
    for (int t = 0; t < TABLE_SIZE; t++) {
        Node* p = table[t];
        while (p) {
            Node* temp = p->next;
            free(p);
            p = temp;
        }
    }

    return false;
}

int main() {
    int nums1[] = {1,2,3,1};
    int k1 = 3;

    int nums2[] = {1,0,1,1};
    int k2 = 1;

    int nums3[] = {1,2,3,1,2,3};
    int k3 = 2;

    printf("Test 1 ? %s\n", containsNearbyDuplicate(nums1, 4, k1) ? "true" : "false");
    printf("Test 2 ? %s\n", containsNearbyDuplicate(nums2, 4, k2) ? "true" : "false");
    printf("Test 3 ? %s\n", containsNearbyDuplicate(nums3, 6, k3) ? "true" : "false");

    return 0;
}
