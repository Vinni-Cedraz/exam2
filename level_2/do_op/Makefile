SRC = my_do_op.c
EXEC = my_do_op 

all: 
	@cc -g -Wall -Wextra -Werror $(SRC) -o $(EXEC)
	@./$(EXEC) "123" "*" 456 | cat -e
	@./$(EXEC) "9828" "/" 234 | cat -e
	@./$(EXEC) "1" "+" "-43" | cat -e
	@./$(EXEC) "" | cat -e
