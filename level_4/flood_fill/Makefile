all : compile_run

compile_run:
		cc -g -Wall -Wextra -Werror my_test.c -o my && ./my "0" "0" >> my_output
		cat my_output
		@make clean --no-print-directory

clean:
	@rm -f my_output ft_output gpt_output gpt gp ft
