SRC = my_rotone.c

all:
	@cc -g -Wall -Werror -Wextra $(SRC) -o my_rotone
	@./my_rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
	@./my_rotone "abc"
	@./my_rotone "AkjhZ zLKIJz , 23y " | cat -e
	@./my_rotone | cat -e
	@./my_rotone "" | cat -e
