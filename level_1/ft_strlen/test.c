#include <assert.h>
#include "my_strlen.c"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char string[9] = "12348";
	char string2[0] = "";
	char string3[12] = "Hello, World";
	assert(my_strlen(string) == (int)strlen(string));
	assert(my_strlen(string2) == (int)strlen(string2));
	assert(my_strlen(string3) == (int)strlen(string3));
	assert(my_strlen(" ") == (int)strlen(" "));
	assert(my_strlen("") == (int)strlen(""));
	assert(my_strlen(NULL) == 0); // segfault check
	assert(my_strlen("\n") == (int)strlen("\n"));
	printf("all tests passed!");
}
