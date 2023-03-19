#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

int how_many(const char **s, char c) {
  int len = 0;
  while (**s == c) {
    len++;
    (*s)++;
  }
  return len;
}

size_t my_strspn(const char *s, const char *accept) {
  int len = 0;
  if (!s || !accept)
    return 0;
  while (*s && *accept) {
    if (*s == *accept)
      len += how_many(&s, *accept);
    accept++;
  }
  return len;
}

//
// int main() {
//   assert(strspn("hello_world", "hell") == my_strspn("hello_world", "hell"));
//   assert(strspn("hello_world", "world") == my_strspn("hello_world", "world"));
//   assert(strspn("hello_world", "hel") == my_strspn("hello_world", "hel"));
//   assert(strspn("hello_world", "_") == my_strspn("hello_world", "_"));
//   assert(strspn("hello_world", "    ") == my_strspn("hello_world", "    "));
//   assert(strspn("hello_world", "hehabc") == my_strspn("hello_world", "hehabc"));
//   assert(strspn("hello_world", "hello_banana_helloA") == my_strspn("hello_world", "hello_banana_helloA"));
//   printf("all tests passed!\n");
// }
