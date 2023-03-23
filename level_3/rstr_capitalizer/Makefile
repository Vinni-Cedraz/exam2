SRC = my_rstr.c

all:
	@cc -g -Wall -Wextra -Werror $(SRC) -o my_rstr_capitalizer
	@./my_rstr_capitalizer | cat -e
	@./my_rstr_capitalizer "a FiRSt LiTTlE TESt" | cat -e
	@./my_rstr_capitalizer "SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
