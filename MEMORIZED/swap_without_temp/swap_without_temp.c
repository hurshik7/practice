#include <stdio.h>

void swap(unsigned int* a, unsigned int* b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

int main(void)
{
	unsigned int a = 11;
	unsigned int b = 22;
	swap(&a, &b);
	printf("%d, %d\n", a, b);
	return 0;
}
