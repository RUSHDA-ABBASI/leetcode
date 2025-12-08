#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &nums[i]);
    }

    int freq[101] = {0};
    int goodPairs = 0;

    for(int i = 0; i < n; i++){
        goodPairs += freq[nums[i]];
        freq[nums[i]]++;
    }

    printf("%d", goodPairs);

    return 0;
}
