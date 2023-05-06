/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:32:09 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/05/06 15:44:32 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define INTMIN -2147483648

static int numlen(int n);
static void build_str(int nbr, char *str, char **iter);
static char *dup(char *s, int n);

char *my_itoa(int nbr) {
    if (nbr == INTMIN) return dup("-2147483648", 12);
    int strlen = nbr == 0 ? 1 : numlen(nbr);
    char *str = malloc(sizeof(char) * strlen + 1);
    char *iter = str;
    if (nbr < 0) *iter = '-', nbr *= -1, iter++;
    build_str(nbr, str, &iter);
    *iter = '\0';
    return (str);
}

static int numlen(int n) {
    int len = 0;
    if (n < 0) len++, n *= -1;
    while (n) n /= 10, len++;
    return len;
}

static void build_str(int nbr, char *str, char **iter) {
    if (nbr > 9) build_str(nbr / 10, str, iter);
    *(*iter)++ = (nbr % 10) + '0';
}

static char *dup(char *s, int n) {
    int i = -1;
    char *dup = malloc((n + 1) * sizeof(char));
    while (++i < n) *(dup + i) = *s++;
	dup[i] = '\0';
    return dup;
}

// ------------TESTS ---------------

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    char *test;

    test = my_itoa(1234);
    assert(!strcmp("1234", test));
    free(test);
    test = my_itoa(87);
    assert(!strcmp("87", test));
    free(test);
    test = my_itoa(9);
    assert(!strcmp("9", test));
    free(test);
    test = my_itoa(0);
    assert(!strcmp("0", test));
    free(test);
    test = my_itoa(-12);
    assert(!strcmp("-12", test));
    free(test);
    test = my_itoa(-122);
    assert(!strcmp("-122", test));
    free(test);
    test = my_itoa(-12999812);
    assert(!strcmp("-12999812", test));
    free(test);
    test = my_itoa(INTMIN);
    assert(!strcmp("-2147483648", test));
    free(test);

    test = my_itoa(-2147483648);
    assert(!strcmp("-2147483648", test));
    free(test);
    printf("all tests passed!");
}
