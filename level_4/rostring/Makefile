all:
	@cc  -g -Wall -Werror -Wextra $(SRC) -o $(EXEC)
	@./$(EXEC) "abc   " | cat -e
	@./$(EXEC) "     AkjhZ zLKIJz , 23y" | cat -e
	@./$(EXEC) "first" "2" "11000000" | cat -e
	@./$(EXEC) "Que la      lumiere soit et la lumiere fut" | cat -e
	@./$(EXEC) "" | cat -e
	@./$(EXEC) "world Hello" "texto" "generico" "so" "pra" "aumentar argumentos" | cat -e
