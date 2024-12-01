#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 10000

void twoSum(int nums[], int nums_size, int target);
int compare(const void* a, const void* b); //for quick sort

int main() {
	int target;
	int nums[MAX_ARRAY_SIZE] = {0};
	int array_size = 0;
	scanf("%d", &target);
	while (scanf("%d", &nums[array_size++]) == 1);
	array_size--;
	twoSum(nums, array_size, target);
	return (0);
}

int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

void twoSum(int nums[], int nums_size, int target) {
	int numSmall = 0;
	int numBig = 0;
	int* numsIndexes = malloc(nums_size * sizeof(int)); //memory allocation for indexes array
	if (numsIndexes == NULL)
		printf("error\n");
	for (int j =0 ; j<nums_size ; j++)
		numsIndexes[j] = nums[j];
	qsort(nums, nums_size, sizeof(int), compare) ;
	int* l = nums;
	int* r = nums + nums_size - 1;
	while (l < r) { //search 2 nums in sorted array
		if (*l + *r < target) l++;
		else if (*l + *r > target) r--;
		else { //taking indexes of *most* early & late appearences
			for (int i = 0 ; i < nums_size ; i++) {
				if (i==0) {
					if (numsIndexes[i] == *l) numSmall = i;
				}
				else if (i==nums_size-1) {
					if (numsIndexes[i] == *r) numBig = i;
				}
				else {
					if (numsIndexes[i] == *l && numsIndexes[i-1] != numsIndexes[i] ) numSmall = i;
					else if (numsIndexes[i] == *r && numsIndexes[i] != numsIndexes[i+1]) numBig = i;
				}
			printf ("(%d, %d)\n" , numSmall, numBig);
			free(numsIndexes);
			return;
			}
		}
	}
}
