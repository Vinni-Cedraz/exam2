SRC = my_str_capitalizer.c

all:
	@cc -g -Wall -Wextra -Werror $(SRC) -o my_str_capitalizer
	@ ./my_str_capitalizer | cat -e
	@ ./my_str_capitalizer "a FiRSt LiTTlE TESt" | cat -e
	@ ./my_str_capitalizer "__SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
