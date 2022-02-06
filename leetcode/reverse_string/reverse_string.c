#include <stdio.h>

void reverseString(char* s, int sSize){
    char* front = s;
    char* back = s + (sSize - 1);
    while (front < back) {
        char temp = *front;
        *front = *back;
        *back = temp;
        front++;
        back--;
    }
}

int main(void) {
    

    return 0;
}
