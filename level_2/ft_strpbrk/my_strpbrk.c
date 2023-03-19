#include <stdio.h>

const char *is_it_any(char s1, const char *s2) {
  while (*s2) {
    if (*s2 == s1)
      break;
    s2++;
  }
  if (!*s2)
    return (NULL);
  return (s2);
}

char *my_strpbrk(const char *s1, const char *s2) {
  if (!s1 || !s2)
    return (0);
  while (s1 && *s1) {
    if (is_it_any(*s1, s2))
      return ((char *)is_it_any(*s1, s2));
    s1++;
  }
  return (NULL);
}

#include <assert.h>
#include <string.h>

int main()
{
	assert(my_strpbrk("hello_world", "a") == strpbrk("hello_world", "a"));
	assert(my_strpbrk("hello_world", "hello_world") == strpbrk("hello_world", "hello_world"));
	assert(strcmp(my_strpbrk("hello_world", "w"), strpbrk("hello_world", "w")));
	assert(strcmp(my_strpbrk("hello_world", "-_w"), strpbrk("hello_world", "-_w")));
	assert(strcmp(my_strpbrk("hello_world", "    -_w"), strpbrk("hello_world", " -_w")));
	assert(strcmp(my_strpbrk("hello_world", "    -_hw"), strpbrk("hello_world", "h -_w")));
	assert(*my_strpbrk("hello_world", "abcd") == *strpbrk("hello_world", "abcd"));
	assert(my_strpbrk("hello_world", "   ") == strpbrk("hello_world", "   "));
	assert(my_strpbrk("hello_world", "") == strpbrk("hello_world", ""));
	assert(my_strpbrk("", "abc_w") == strpbrk("", "abc_w"));
	printf("all tests passed!");
}
