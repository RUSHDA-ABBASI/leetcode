#include <stdio.h>
int main ()
{
	int nums[] = {2,7,11,15};
	int target = 9;
	int n = sizeof(nums)/ sizeof(nums[0]);
	
	for (int i = 0; i < n; i++){
	for (int j = i + 1; j < n; j++){
		if (nums[i] + nums[j] == target){
		
			printf(" indices : %d and %d(values: %d + %d)\n", i, j, nums[i], nums[j], target);
			return 0;
		}
	}
			
	}
	
	printf("no solution found\n");

	return 0;
}