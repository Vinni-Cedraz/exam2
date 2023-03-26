
SRC = my_wdmatch.c

all:
	@cc -g -Wall -Wextra -Werror $(SRC) -o wdmatch
	./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
	@echo expected: faya$
	./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
	@echo expected: $
	./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
	@echo expected: quarante deux$
	./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
	@echo expected: $
	./wdmatch "localidade" "vmnolbvmbnlcalidade" | cat -e
	@echo expected: $
	./wdmatch | cat -e
	@echo expected: $
