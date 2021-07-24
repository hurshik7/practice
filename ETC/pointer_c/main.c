#include <stdio.h>
#include <stdlib.h>

typedef struct foo {
	int a;
	int b;
} foo_t;

int main(void)
{
	foo_t* pp = malloc(sizeof(foo_t));
	pp->a = 10;
	pp->b = 20;
	printf("%d\n", ++pp->a);
	return 0;
}
