SRC = my_add_prime_sum.c

all:
	@cc -g -Wall -Wextra -Werror $(SRC) -o my_add_prime_sum
	@./my_add_prime_sum 5
	@echo expected 10
	@./my_add_prime_sum 7 | cat -e
	@echo expected 17$
	@./my_add_prime_sum 100 | cat -e
	@echo expected 1060$
	@./my_add_prime_sum 1000 | cat -e
	@echo expected 76127$
