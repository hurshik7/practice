#include <stdio.h>
#include <stdbool.h>

bool isSubString(const char* str1, const char* str2) {
    if (str1 == NULL || str2 == NULL) {
        return false;
    }
    if (*str1 == '\0') {
        return true;
    }

    const char* ptr1 = str1;
    const char* ptr2 = str2;
    while (*ptr2 != '\0') {
        const char* currentStr2Ptr = ptr2;
        ptr1 = str1;
        while (*ptr1 == *currentStr2Ptr && *ptr1 != '\0') {
            ptr1++;
            currentStr2Ptr++;
        }
        if (*ptr1 == '\0') {
            return true;
        }
        ptr2++;
    }
    
    return false;
}

int main(void) {
    printf("%d\n", isSubString("aac", "aaac"));
    return 0;
}
