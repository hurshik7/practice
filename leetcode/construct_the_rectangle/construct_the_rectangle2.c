#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

void printArr(int* arr, int arrSize);
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructRectangle(int area, int* returnSize){
    int* retArr = (int*)malloc(128 * sizeof(int));
    *returnSize = 2;
    for (int i = (int)sqrt((double)area); i >= 1; i--) {
        if (area % i == 0) {
            retArr[1] = i;
            retArr[0] = area / i;
            break;
        }
    }    
    return retArr;
}

void printArr(int* arr, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int retSize = 0;
    int* result1 = constructRectangle(4, &retSize);
    printArr(result1, retSize);
    free(result1);
    
    int retSize2 = 0;
    int* result2 = constructRectangle(37, &retSize2);
    printArr(result2, retSize2);
    free(result2);
    return 0;
}
