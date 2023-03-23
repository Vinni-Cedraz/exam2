SRC = my_print_hex.c

all:
	@cc -g -Wall -Wextra -Werror $(SRC) -o my_print_hex
	@printf "my_answer1: ";
	@./my_print_hex "10" | cat -e
	@printf "correct answer1: a"
	@printf "\n";
	@printf "my_answer2: ";
	@./my_print_hex "255" | cat -e
	@printf "correct answer2: ff"
	@printf "\n";
	@printf "my_answer3: ";
	@./my_print_hex "5156454" | cat -e
	@printf "correct answer3: 4eae66"
