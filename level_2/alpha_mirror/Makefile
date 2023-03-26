# variable
SRC = my_alpha_mirror.c
RUN = ./my_alpha_mirror
CFLAGS = -Wall -Wextra -Werror -O3

all: compile run

compile:
	$(CC) $(CFLAGS) $(SRC) -o $(RUN)

run:
	$(RUN) "abc" | cat  -e
	$(RUN) "My horse is Amazing." | cat -e
	$(RUN) "a-b-c-" | cat -e
	$(RUN) "z-y0x0" | cat -e
	$(RUN) "nnnn" | cat -e
	$(RUN) "nnnn" "aaaa" | cat -e
	$(RUN) | cat -e
