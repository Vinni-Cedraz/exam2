SRC = my_repeat_alpha.c
C = cc -Wall -Wextra -Werror

all:
	$(C) $(SRC) -o repeat_alpha
	./repeat_alpha "abc"
	./repeat_alpha "Alex." | cat -e
	./repeat_alpha 'abacadaba 42!' | cat -e
	./repeat_alpha | cat -e
	./repeat_alpha "" | cat -e
