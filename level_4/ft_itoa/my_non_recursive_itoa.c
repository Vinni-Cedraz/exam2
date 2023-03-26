#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strcpyrev(char *str, int len) {
    int i = 0;
    int last = len;
    char *revcpy = malloc((len + 1) * sizeof(char));
    while (len) revcpy[i++] = str[--len];
    revcpy[last] = '\0';
    free(str);
    return (revcpy);
}

int my_numlen(int nbr) {
    int i = 1;
    if (!nbr) return (1);
    if (nbr == -2147483648) nbr++;
    if (nbr < 0) {
        i++;
        nbr = -nbr;
    }
    while (nbr && i++) nbr /= 10;
    return (i - 1);
}

char *my_non_recursive_itoa(int nbr) {
    int numlen = my_numlen(nbr);
    char *ascii = malloc(sizeof(char) * (numlen + 1));
    int n_iter = nbr;
    int i = 0;

    // edge cases:
    ascii[numlen] = '\0';
    if (!n_iter) {
        ascii[0] = '0';
        return (ascii);
    }
    if (n_iter == -2147483648) n_iter++;
    if (n_iter < 0) {
        ascii[numlen - 1] = '-';
        n_iter = -n_iter;
    }

    // main loop
    while (n_iter) {
        ascii[i++] = (n_iter % 10) + '0';
        n_iter /= 10;
    }
    if (nbr == -2147483648) ascii[0] = 8 + '0';
    return (strcpyrev(ascii, numlen));
}

int main() {
    char *test;

    test = my_non_recursive_itoa(1234);
    assert(!strcmp("1234", test));
    free(test);
    test = my_non_recursive_itoa(87);
    assert(!strcmp("87", test));
    free(test);
    test = my_non_recursive_itoa(9);
    assert(!strcmp("9", test));
    free(test);
    test = my_non_recursive_itoa(0);
    assert(!strcmp("0", test));
    free(test);
    test = my_non_recursive_itoa(-12);
    assert(!strcmp("-12", test));
    free(test);
    test = my_non_recursive_itoa(-122);
    assert(!strcmp("-122", test));
    free(test);
    test = my_non_recursive_itoa(-12999812);
    assert(!strcmp("-12999812", test));
    free(test);
    test = my_non_recursive_itoa(-2147483648);
    assert(!strcmp("-2147483648", test));
    free(test);
    printf("all tests passed!");
}
