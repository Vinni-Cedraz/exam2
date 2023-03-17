# include <stddef.h>

size_t	my_strcspn(const char *s, const char *reject) {
  const char *end = s;
  while (end && *end) {
	if (*end == *reject)
	  break;
	end++;
  }
  return (end - s);
}

//
// #include <assert.h>
// #include <stdio.h>
// #include <string.h>
//
// int main()
// {
//   assert(strcspn("hello_world", "_") == my_strcspn("hello_world", "_"));
//   assert(strcspn("abacate*muito*doido", "*") == my_strcspn("abacate*muito*doido", "*"));
//   assert(strcspn("abacate muito doido", " ") == my_strcspn("abacate muito doido", " "));
//   assert(strcspn("abacate+-*muitodoido", "+-*") == my_strcspn("abacate+-*muitodoido", "+-*"));
//   assert(strcspn("acabate+-*muitodoido", "+") == my_strcspn("abacate+-*muitodoido", "+"));
//   assert(strcspn("hello_world", "42") == my_strcspn("hello_world", "42"));
//   printf("all tests passed");
// }
