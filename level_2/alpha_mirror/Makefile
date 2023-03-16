# variable
SRC = my_alpha_mirror.c
RUN = ./a.out
CFLAGS = -Wall -Wextra -Werror -g

all: compile run

compile:
	$(CC) $(CFLAGS) $(SRC)

run:
	$(RUN) "abc"
	$(RUN) "My horse is Amazing." | cat -e
	$(RUN) | cat -e
