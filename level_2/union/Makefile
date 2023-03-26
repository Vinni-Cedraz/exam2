SRC = my_union.c

all:
	@cc -g -Wall -Wextra -Werror $(SRC) -o my_union
	./my_union "zpadinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
	@echo expected: zpadintoqefwjy$
	./my_union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
	@echo expected: df6vewg4thras$
	./my_union "rien" "cette phrase ne cache rien" | cat -e
	@echo expected: rienct phas$
	@./my_union | cat -e
	@echo expected: $
	./my_union "rien" | cat -e
	@echo expected: $
