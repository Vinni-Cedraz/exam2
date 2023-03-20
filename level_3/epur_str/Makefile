SRC = my_epur_str.c
all:
	@cc -g -Wall -Wextra -Werror $(SRC) -o my_epur_str
	@./my_epur_str "See? It's easy to print the same thing" | cat -e
	@./my_epur_str " this        time it      will     be    more complex  . " | cat -e
	@./my_epur_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." "this should be ignored"| cat -e
	@./my_epur_str "" | cat -e
