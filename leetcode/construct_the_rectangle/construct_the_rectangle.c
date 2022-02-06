#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

void printArr(int* arr, int arrSize);
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int getMeasures(int num, int* measures, int measuresSize) {
    int measureCount = 0;
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            if (measureCount < measuresSize) {
                measures[measureCount] = i;
                measureCount++;
            }
        }
    }
    return measureCount;
}

int* constructRectangle(int area, int* returnSize){
    int* retArr = (int*)malloc(128 * sizeof(int));
    int measures[1024] = {0, };
    *returnSize = 2;
    int measureCount = getMeasures(area, measures, 1024);
    int diff = INT_MAX; 
    int diffIndexA = -1;
    int diffIndexB = -1;
    int front = 0;
    int back = measureCount - 1;
    while (front <= back) {
        int tempDiff = measures[back] - measures[front];
        if (tempDiff < diff) {
            diffIndexA = back;
            diffIndexB = front;
            diff = tempDiff;
        }
        front++;
        back--;
    }
    retArr[0] = measures[diffIndexA];
    retArr[1] = measures[diffIndexB];
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
