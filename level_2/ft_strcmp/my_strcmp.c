#include <assert.h>
#include <stdio.h>
#include <string.h>
int ft_strcmp(char *s1, char *s2) {
  while (s1 && *s1 && s2 && *s2) {
    if (*s1 > *s2)
      return (1);
    else if (*s1 < *s2)
      return (-1);
    s1++, s2++;
  }
  return (0);
}

int main() {
  assert(ft_strcmp("hey", "hey") == strcmp("hey", "hey"));
  assert(ft_strcmp("hey", "hoi") == strcmp("hey", "a"));
  printf("all tests passed!");
}
