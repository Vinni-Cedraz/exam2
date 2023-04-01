#include <unistd.h>

// ------------------------------- //
static int is_whitespace(char);
static int my_putuntil(char *);
// ------------------------------- //
static char *next_valid_char(char *);
static char *get_next_word(char *);
// ------------------------------- //

int main(int argc, char **argv) {
    char *str = argv[1];
    char *first_word;
    char *next_word;

    if (argc < 2) return (my_putuntil("\n"));
    first_word = next_valid_char(str);
    next_word = get_next_word(first_word);
    while (next_word) {
        my_putuntil(next_word);
        my_putuntil(" ");
        next_word = get_next_word(next_word);
    }
    my_putuntil(first_word);
    my_putuntil("\n");
}

// ------------------------------- //

static  int is_whitespace(char c) { return (c == ' ' || c == '\t'); }

static  char *next_valid_char(char *s) {
    while (is_whitespace(*s)) s++;
    if (*s == '\0') return (NULL);
    return (s);
}

/* Simply returns the next valid char after a whitespace is
   found. if no whitespace is found it returns NULL */
static  char *get_next_word(char *s) {
    while (s && *s) {
        if (is_whitespace(*s)) return (next_valid_char(s));
        s++;
    }
    return (NULL);
}

static  int my_putuntil(char *s) {
    while (s && *s) {
        write(1, s++, 1);
        if (is_whitespace(*s)) break;
    }
    return (1);
}
