#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int repeatedStringMatch(char* a, char* b)
{
    if (a == NULL || b == NULL) {
        return -1;
    }
    if (*b == '\0') {
        return 0;
    }
    if (strcmp(a, b) == true) {
        return 1;
    }
    size_t aSize = strlen(a);
    size_t bSize = strlen(b);
    bool alphabet[26] = {
        0,
    };
    for (size_t i = 0; i < aSize; i++) {
        alphabet[a[i] - 'a'] = true;
    }
    for (size_t i = 0; i < bSize; i++) {
        if (alphabet[b[i] - 'a'] != true) {
            return -1;
        }
    }

    int count = bSize / aSize;
    printf("count: %d\n", count);
    char newStr[4096 * 2];
    strcpy(newStr, a);
    for (int i = 0; i < count; i++) {
        strcat(newStr, a);
    }
    if (strstr(newStr, b) != NULL) {
        return count;
    }
    strcat(newStr, a);
    if (strstr(newStr, b) != NULL) {
        return count + 1;
    }

    strcat(newStr, a);
    if (strstr(newStr, b) != NULL) {
        return count + 2;
    }
    return -1;
}

int main(void)
{
    printf("%d\n", repeatedStringMatch("abcd", "cdabcdab"));
    printf("%d\n", repeatedStringMatch("a", "aa"));
    printf("%d\n", repeatedStringMatch("abcabcabcabc", "abac"));
    return 0;
}
