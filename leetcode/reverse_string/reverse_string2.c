#include <stdio.h>

void reverseString(char* s, int sSize){
    if (sSize <= 1) {
        return;
    }
    char temp = *s;
    *s = *(s + (sSize - 1));
    *(s + sSize - 1) = temp;
    reverseString(s + 1, sSize - 2);
}

int main(void) {
    

    return 0;
}
