#include <unistd.h>

static inline void my_putchar(char c) { write(1, &c, 1); }
static inline void my_snake_to_camel(char *s) {
  while (s && *s) {
    if (*s != '_')
      my_putchar(*s);
    else if (*s == '_')
      my_putchar((*(++s)) - 32);
    s++;
  }
  my_putchar('\n');
}

int main(int argc, char **argv) { my_snake_to_camel(argv[1]); }
