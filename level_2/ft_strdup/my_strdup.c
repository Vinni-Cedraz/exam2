#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int my_strlen(char *str) {
  char *end = str;
  while (end && *end)
    end++;
  return (end - str);
}

char *my_strdup(char *src) {
  char *dup, *res;
  res = dup = malloc(my_strlen(src) * sizeof(char) + 1);
  while (src && *src)
    *dup++ = *src++;
  dup[my_strlen(src)] = '\0';
  return (res);
}

// #include <assert.h>
// int main()
// {
// 	char str[11] = "Hello World";
// 	char *dup;
// 	char *mydup;
//
// 	// test1
// 	dup = strdup("Hello World");
// 	mydup = my_strdup("Hello World");
// 	assert(!strcmp(dup, mydup));
// 	free(dup), free(mydup);
// 	// test2
// 	dup = strdup("    Hello World");
// 	mydup = my_strdup("    Hello World");
// 	assert(!strcmp(dup, mydup));
// 	free(dup), free(mydup);
//
// 	// test3
// 	dup = strdup("");
// 	mydup = my_strdup("");
// 	assert(!strcmp(dup, mydup));
// 	free(dup), free(mydup);
// 	printf("all tests passed!");
// }
