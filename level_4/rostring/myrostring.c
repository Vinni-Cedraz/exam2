#include <unistd.h>

// ------------------------------- //
static int is_whitespace(char);
static int my_putstr(char *);
// ------------------------------- //
static char *next_valid_char(char *);
static char *get_next_word(char *);
// ------------------------------- //

int main(int argc, char **argv) {
  char *str = argv[1];
  char *first_word;
  char *next_word;

  if (argc < 2)
    return (my_putstr("\n"));
  first_word = next_valid_char(str);
  next_word = get_next_word(first_word);
  while (next_word) {
    my_putstr(next_word);
    my_putstr(" ");
    next_word = get_next_word(next_word);
  }
  my_putstr(first_word);
  my_putstr("\n");
}

// ------------------------------- //

static inline int is_whitespace(char c) { return (c == ' ' || c == '\t'); }

static inline char *next_valid_char(char *s) {
  while (is_whitespace(*s))
    s++;
  if (*s == '\0')
    return (NULL);
  return (s);
}

static inline char *get_next_word(char *s) {
  while (s && *s) {
    if (is_whitespace(*s))
      return (next_valid_char(s));
    s++;
  }
  return (NULL);
}

static inline int my_putstr(char *s) {
  while (s && *s) {
    write(1, s++, 1);
    if (is_whitespace(*s))
      break;
  }
  return (1);
}
