all:
	@printf "my_version:"
	cc -Wall -Wextra -Werror -g my_test.c && valflags ./a.out
	@printf "\n"
	@printf "correct version:"
	cc -Wall -Wextra -Werror -g test.c && valflags ./a.out
	@printf "\n"
