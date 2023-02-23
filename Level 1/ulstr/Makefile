SRC = my_ulstr.c
EXE = ulstr
RUN = ./$(EXE)
FLAGS = -Wall -Wextra -Werror -g

all: compile create_test eyeball_it diff_it

compile:
		@$(CC) $(FLAGS) $(SRC) -o $(EXE)

create_test:
		@$(RUN) "L'eSPrit nE peUt plUs pRogResSer s'Il staGne et sI peRsIsTent VAnIte et auto-justification." >> teststr1
		@$(RUN) "S'enTOuRer dE sECreT eSt uN sIGnE De mAnQuE De coNNaiSSanCe.  " >> teststr2
		@$(RUN) "3:21 Ba  tOut  moUn ki Ka di KE m'en Ka fe fot" >> teststr3
		@$(RUN) "" >> teststr4

eyeball_it:
		cat -e teststr1
		cat -e testref1
		cat -e teststr2
		cat -e testref2
		cat -e teststr3
		cat -e testref3
		cat -e teststr4
		cat -e testref4

diff_it:
		@diff teststr1 testref1 && echo "Test 1 passed!" || echo "Test 1 failed :("
		@diff teststr2 testref2 && echo "Test 2 passed!" || echo "Test 2 failed :("
		@diff teststr3 testref3 && echo "Test 3 passed!" || echo "Test 3 failed :("
		@diff teststr4 testref4 && echo "Test 4 passed!" || echo "Test 4 failed :("
		@make clean --no-print-directory

clean :
		@rm -f teststr*
