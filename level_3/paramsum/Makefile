SRC = my_paramsum.c

all:
	@cc -g -Wall -Werror -Wextra $(SRC) -o my_paramsum
	@./my_paramsum 1 2 3 5 7 24
	@./my_paramsum 6 12 24 | cat -e
	@./my_paramsum | cat -e
