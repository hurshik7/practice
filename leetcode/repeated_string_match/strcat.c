#include <stdio.h>
#include <string.h>

int main(void) {
    char str1[2048] = "";
    char str2[] = "abcd";
    strcat(str1, str2);
    strcat(str1, str2);
    strcat(str1, str2);
    printf("%s\n", str1);
}
