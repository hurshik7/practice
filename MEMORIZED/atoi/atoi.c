#include <stdio.h>
#include <stddef.h>

int my_atoi(const char* str)
{
	int ret = 0;
	int sign = 1;
	const char* ptr = str;
	printf("atoi start\n");
	while (*ptr == ' ') {
		printf("while space\n");
		ptr++;
	}

	if (*ptr == '-') {
		sign = -1;
		ptr++;
	} else if (*ptr == '+') {
		ptr++;
	} else if (*ptr < '0' || *ptr > '9') {
		return 0;
	}
	
	while (*ptr != '\0') {
		char temp = *ptr;
		if (temp < '0' || temp > '9') {
			return 0;
		} 
		ret = ret * 10 + (temp - '0');
	}
	return sign * ret;
}

int main(void)
{
	printf("program start!\n");
	printf("%d\n", my_atoi("123"));
	printf("%d\n", my_atoi("    a1234"));
	printf("%d\n", my_atoi("    -1234"));
	printf("%d\n", my_atoi("    12sdf34"));
	printf("%d\n", my_atoi("    1234a"));
	printf("%d\n", my_atoi("    -1234bd"));
	printf("%d\n", my_atoi("    -1234adfv"));
	return 0;
}
