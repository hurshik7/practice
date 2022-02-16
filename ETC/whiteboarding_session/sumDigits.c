#include <stdio.h>

int sumOfDigits(int n) {
    int sum = n % 10;
    while (n != 0) {
        n = n / 10;
        sum += n % 10;
    }
    sum += n;
    return sum;
}

int main(void) {
    printf("%d\n", sumOfDigits(84));
    printf("%d\n", sumOfDigits(123));
    printf("%d\n", sumOfDigits(594));
}
