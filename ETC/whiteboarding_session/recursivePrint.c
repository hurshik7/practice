#include <stdio.h>

void printCol(int n) {
    if (n == 0) {
        return;
    }
    printCol(n - 1);
    printf("%d ", n);
}

void printRecursive(int n) {
    if (n == 0) {
        return;
    }
    printRecursive(n - 1);
    printCol(n);
    printf("\n");
}

int main(void) {
    printRecursive(70);
    return 0;
}

/*
printRecursive(5)
printRecursive(4)
printRecursive(3)
printRecursive(2)
printRecursive(1)
printRecursive(0)
printCol(1)
printCol(0)
1
printCol(2)
1 2
printCol(3)
1 2 3
printCol(4)
1 2 3 4
printCol(5)
1 2 3 4 5
*/

