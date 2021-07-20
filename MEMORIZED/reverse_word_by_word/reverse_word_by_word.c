#include <stdio.h>

void reverse(char* start, char* end)
{
	while (start < end) {
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

void reverse_word_by_word(char* str)
{
	char* word_begin = str;
	char* temp = str;

	while (*temp != '\0') {
		temp++;
		if (*temp == '\0') {
			reverse(word_begin, temp - 1);
		} else if (*temp == ' ') {
			reverse(word_begin, temp - 1);
			word_begin = temp + 1;
		}
	}	
	reverse(str, temp - 1);
}

int main(void)
{
	char str[] = "I like this";
	reverse_word_by_word(str);
	printf("%s\n", str);
	return 0;
}
