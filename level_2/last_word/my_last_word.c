#include <stdio.h>
#include <unistd.h>

static inline int is_whitespace(char c) {
	return (c == '\t' || c == ' ');
}

static inline int my_putstr(char *str) {
	while (str && *str && !is_whitespace(*str))
		write (1, str++, 1);
	return (1);
}

static inline int my_strlen(char *str) {
  	char *end = str;
  	while (end && *end)
    	end++;
  	return (end - str);
}

static inline int last_valid_word(char *str, int index) {
	while (is_whitespace(str[index]))
		index--;
	while (index != -1 && !is_whitespace(str[index]))
		index--;
  	return (index + 1);
}

int main(int argc, char **argv) {
  	if ((argc != 2) || (*argv[1] == '\0'))
    	return (my_putstr("\n"));
	int len = my_strlen(argv[1]);
	int last_word_index = last_valid_word(argv[1], len - 1);
	my_putstr(&argv[1][last_word_index]);
	my_putstr("\n");
}
