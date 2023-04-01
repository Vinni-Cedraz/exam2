#include <unistd.h>

static  int is_lower(char c) { return (c >= 'a' && c <= 'z'); }

static  void putlower(char *c) {
  char lower = *c + 32;
  write(1, &lower, 1);
}

static  void write_loop(char *s) {
  while (s && *s) {
    if (is_lower(*s))
      write(1, s, 1);
    else if (*s == ' ')
      write(1, " ", 1);
    else if (*s == '\t')
      write(1, "\t", 1);
    else {
      write(1, "_", 1);
      putlower(s);
    }
    s++;
  }
  write(1, "\n", 1);
}

int main(int argc, char **argv) {
  if (argc != 2)
    return (write(1, "\n", 1));
  write_loop(argv[1]);
}
