#include <string.h>
#include <stdio.h>

int main(void) {
    char str1[] = "abcdabcd";
    char str2[] = "cdabcdab";

    char* sub = strstr(str1, str2);
    printf("%s\n", sub);
    return 0;
}
