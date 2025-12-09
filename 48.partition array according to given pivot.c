#include <stdio.h>

int main(){
    int nums[] = {9,12,5,10,14,3,10};
    int n = sizeof(nums)/sizeof(nums[0]);
    int pivot = 10;

    int less[100], equal[100], greater[100];
    int l=0,e=0,g=0;

    for(int i=0;i<n;i++){
        if(nums[i] < pivot) less[l++] = nums[i];
        else if(nums[i] == pivot) equal[e++] = nums[i];
        else greater[g++] = nums[i];
    }

    // print final result
    for(int i=0;i<l;i++) printf("%d ", less[i]);
    for(int i=0;i<e;i++) printf("%d ", equal[i]);
    for(int i=0;i<g;i++) printf("%d ", greater[i]);

    return 0;
}
