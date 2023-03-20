SRC = my_expand_str.c

all :
	@cc -g -Wall -Wextra -Werror $(SRC) -o my_expand_str
	@./my_expand_str "See? It's easy to print the same thing" | cat -e
	@./my_expand_str " this        time it      will     be    more complex  " | cat -e
	@./my_expand_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
	@./my_expand_str "" | cat -e
