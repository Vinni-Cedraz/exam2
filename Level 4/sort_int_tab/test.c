#include "my_sort_int_tab.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int i = -1;
	int *unsorted_tab;
	int size = 99999;
	int sz = 99999;

	unsorted_tab = calloc(sizeof(int), size + 1);
	while (i++ < size)
		unsorted_tab[i] = sz--;
	i = -1;
	size = 99999;
	while (++i < size)
		printf("unsorted_tab: %d\n", unsorted_tab[i]);
	printf("\n\n\n");
	i = -1;
	my_sort_int_tab(unsorted_tab, size);
	while (++i < size)
		printf("sorted_tab: %d\n", unsorted_tab[i]);
	free(unsorted_tab);
}
