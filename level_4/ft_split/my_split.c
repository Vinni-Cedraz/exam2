#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void lenstrcopy(char *s1, char *s2, int len);
static int is_whitespace(char c);
static char *next_whitespace(char *str);
static char *next_valid_char(char *str);
static int wordcounter(char *str);

char **my_split(char *str) {
    char *start;
    char *end;

    int index = -1;
    int word_count = wordcounter(str);
    char **split = malloc(sizeof(char *) * (word_count + 1));
    split[word_count] = NULL;
    while (++index < word_count) {
        start = next_valid_char(str);
        end = next_whitespace(start);
        split[index] = malloc((end - start) + 1);
        lenstrcopy(split[index], start, end - start);
        str = end;
    }
    return (split);
}

static int wordcounter(char *s) {
    int inside_word = 0;
	int last_char = 0;
    int wd_count = 0;
    while (*s) {
        inside_word = is_whitespace(*s) ? 0 : 1;
		last_char = is_whitespace(*(s + 1)) ? 1 : 0;
        if (inside_word && last_char) wd_count++;
        s++;
    }
    return (wd_count);
}

static void lenstrcopy(char *s1, char *s2, int len) {
    int i = -1;
    while (++i < len && s2[i]) s1[i] = s2[i];
    s1[i] = '\0';
}

static int is_whitespace(char c) {
    return (c == ' ' || c == '\t' || c == '\0');
}

static char *next_whitespace(char *str) {
    while (!is_whitespace(*str)) str++;
    return (str);
}

static char *next_valid_char(char *str) {
    while (is_whitespace(*str)) str++;
    return (str);
}

// ------------------TEST-FUCKING-TEST----------------------//

#include <stdio.h>
#include <stdlib.h>

static void my_free_arr(char **arr, void **aux);
static void print_arr(char **arr);

int main(void) {
    char *s;
    char **split;

    s = "         Hello World, this is a     test		";
    split = my_split(s);
    print_arr(split);
    my_free_arr(split, (void **)split);
    return (0);
}

static inline void my_free_arr(char **arr, void **aux) {
    while (arr && *arr) free(*arr++);
    free(aux);
}

static inline void print_arr(char **arr) {
    while (*arr) printf("%s\n", *arr++);
}
