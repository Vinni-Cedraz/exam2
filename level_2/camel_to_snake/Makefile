SRC = my_camel_to_snake.c
EXEC = my_camel_to_snake

all: 
	@cc -g -Wall -Wextra -Werror $(SRC) -o $(EXEC)
	@./$(EXEC) "hereIsACamelCaseWord" | cat -e
	@./$(EXEC) "pacmanIsGame" | cat -e
	@./$(EXEC) "helloWorld" | cat -e
	@./$(EXEC) "" | cat -e
