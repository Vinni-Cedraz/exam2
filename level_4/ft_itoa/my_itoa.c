/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:32:09 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/05/10 17:35:34 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int numlen(int n);
static void build_str(long int nbr, char *str, char **iter);

char *my_itoa(int nbr) {
    int strlen = numlen(nbr);
    char *str = malloc(sizeof(char) * strlen + 1);
    char *iter = str;
    long int n = (long int)nbr;
    if (n < 0) *iter = '-', n *= -1, iter++;
    build_str(n, str, &iter);
    *iter = '\0';
    return (str);
}

static int numlen(int n) {
    int len = 0;
    if (n == 0) return 1;
    if (n < 0) len++, n *= -1;
    while (n) n /= 10, len++;
    return len;
}

static void build_str(long int nbr, char *str, char **iter) {
    if (nbr > 9) build_str(nbr / 10, str, iter);
    *(*iter)++ = (nbr % 10) + '0';
}

// // ------------TESTS ---------------
//
// #include <assert.h>
// #include <stdio.h>
// #include <string.h>
// #include <unistd.h>
// #define INTMIN -2147483648
// int main(void) {
//     char *test;
//
//     test = my_itoa(1234);
//     assert(!strcmp("1234", test));
//     free(test);
//     test = my_itoa(87);
//     assert(!strcmp("87", test));
//     free(test);
//     test = my_itoa(9);
//     assert(!strcmp("9", test));
//     free(test);
//     test = my_itoa(0);
//     assert(!strcmp("0", test));
//     free(test);
//     test = my_itoa(-12);
//     assert(!strcmp("-12", test));
//     free(test);
//     test = my_itoa(-122);
//     assert(!strcmp("-122", test));
//     free(test);
//     test = my_itoa(-12999812);
//     assert(!strcmp("-12999812", test));
//     free(test);
//     test = my_itoa(INTMIN);
//     assert(!strcmp("-2147483648", test));
//     free(test);
//     test = my_itoa(-2147483648);
//     assert(!strcmp("-2147483648", test));
//     free(test);
//     printf("all tests passed!");
// }
