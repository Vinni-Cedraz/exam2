SHELL := /bin/bash
EXECUTABLE = search_and_replace
RUN := ./$(EXECUTABLE)
SRC = my_search_and_replace.c
COMPILATION_FLAGS = -g

all : compile run_tests

compile:
	$(CC) $(COMPILATION_FLAGS) $(SRC) -o $(EXECUTABLE)

run_tests:
	$(RUN) "Hello World" "l" "a"
	$(RUN) "Hello World" "o" "h"
	$(RUN) "Papache est un sabre" "a" "o"
	$(RUN) "zaz" "art" "zul" | cat -e
	$(RUN) "zaz" "r" "u" | cat -e
	$(RUN) "jacob" "a" "b" "c" "e" | cat -e
	$(RUN) "ZoZ eT Dovid oiME le METol." "o" "a" | cat -e
	$(RUN) "wNcOre Un ExEmPle Pas Facilw a Ecrirw " "w" "e" | cat -e
