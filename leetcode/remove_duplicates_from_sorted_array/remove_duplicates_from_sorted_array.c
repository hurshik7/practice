#include <stdio.h>
#include <stdlib.h>

int comp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int removeDuplicates(int* nums, int numsSize){
    if (numsSize == 0) {
        return 0;
    }
    int maxNum = nums[numsSize - 1] + 1;
    int currNum = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == currNum) {
            nums[i] = maxNum;
        } else {
            currNum = nums[i];
        }
    }

    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != maxNum) {
            count++;
        }
    }
    qsort(nums, numsSize, sizeof(int), comp);
    return count;
}

void printArr(int* nums, int numSize) {
    for (int i = 0; i < numSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main(void) {
    int arr1[] = {1, 1, 2};
    printf("%d\n", removeDuplicates(arr1, 3));
    printArr(arr1, 3);

    int arr2[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    printf("%d\n", removeDuplicates(arr2, 10));
    printArr(arr2, 10);
    return 0;
}
