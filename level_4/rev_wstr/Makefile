SRC = my_rev_wstr.c

all:
	@cc -g -Wall -Wextra -Werror $(SRC) -o my_rev_wstr
	@ ./my_rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
	@ ./my_rev_wstr "abcdefghijklm" | cat -e
	@ ./my_rev_wstr "Wingardium Leviosa" | cat -e
	@ ./my_rev_wstr | cat -e
