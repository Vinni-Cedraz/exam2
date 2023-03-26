SRC = my_ulstr.c
EXE = ulstr
RUN = ./$(EXE)
FLAGS = -Wall -Wextra -Werror -g

all: compile test

compile:
		@$(CC) $(FLAGS) $(SRC) -o $(EXE)

test:
		@$(RUN) "L'eSPrit nE peUt plUs pRogResSer s'Il staGne et sI peRsIsTent VAnIte et auto-justification." | cat -e
		@$(RUN) "S'enTOuRer dE sECreT eSt uN sIGnE De mAnQuE De coNNaiSSanCe.  " | cat -e
		@$(RUN) "3:21 Ba  tOut  moUn ki Ka di KE m'en Ka fe fot" | cat -e
		@$(RUN) "" | cat -e
