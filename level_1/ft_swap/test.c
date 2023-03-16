#include "my_swap.c"
#include <stdio.h>

int main(void)
{
	int a;
	int b;
	
	a = 1;
	b = 3;
	printf("a = %d, b = %d\n", a, b);
	my_swap(&a, &b);
	printf("a = %d, b = %d\n", a, b);
}
