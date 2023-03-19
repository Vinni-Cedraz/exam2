SRC = my_last_word.c

all:
	@cc -g -Wall -Wextra -Werror $(SRC) -o my_last_word
	@./my_last_word "FOR PONY" | cat -e
	@./my_last_word "this        ...       is sparta, then again, maybe    not" | cat -e
	@./my_last_word "a" "b" | cat -e
	@./my_last_word "   " | cat -e
	@./my_last_word "  lorem,ipsum  " | cat -e
	@rm -f my_last_word
