SRC = my_rot_13.c

all:
	@cc -g -Wall -Wextra -Werror $(SRC) -o my_rot_13
	@./my_rot_13 "abc" | cat -e
	@./my_rot_13 "My horse is Amazing." | cat -e
	@./my_rot_13 "AkjhZ zLKIJz , 23y " | cat -e
	@./my_rot_13 | cat -e
	@./my_rot_13 "" | cat -e
