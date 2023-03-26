/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:52:51 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/26 17:53:30 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int my_strlen(const char *s);
static int digit_value(char c);
static int my_pow(int base, int exp);

int my_atoi_base(const char *str, int str_base) {
    int pos = 0;
    int decimal = 0;
    int len = my_strlen(str) - 1;
    int sign = (*str == '-') ? -1 : 1;
    while (len + 1) {
        if ((len == 0) && sign == -1) break;
        decimal += digit_value(str[len--]) * my_pow(str_base, pos++);
    }
    return (sign * decimal);
}

static int my_strlen(const char *s) {
    const char *end = s;
    while (end && *end) end++;
    return end - s;
}

static int digit_value(char c) {
    int index = -1;

    // lowercase digit:
    static const char s[] = {"0123456789abcdef"};
    while (s[++index])
        if (c == s[index]) return index;

    index = -1;

    // uppercase:
    static const char s_up[] = {"0123456789ABCDEF"};
    while (s_up[++index])
        if (c == s_up[index]) return index;

    // fail:
    return (-1);
}

static int my_pow(int base, int exp) {
    if (exp == 0) return 1;
    if (exp == 1) return base;
    int tmp = base;
    while (--exp) base *= tmp;
    return base;
}

// // ============================== TESTS ==================================//
// #include <assert.h>
// #include <stdio.h>
// #include <stdlib.h>
// int main() {
//     assert(my_atoi_base("0", 10) == 0);
//     assert(my_atoi_base("1", 10) == 1);
//     assert(my_atoi_base("10", 10) == 10);
//     assert(my_atoi_base("100", 10) == 100);
//     assert(my_atoi_base("1000", 10) == 1000);
//     assert(my_atoi_base("-1", 10) == -1);
//     assert(my_atoi_base("-10", 10) == -10);
//     assert(my_atoi_base("-100", 10) == -100);
//     assert(my_atoi_base("-1000", 10) == -1000);
//     assert(my_atoi_base("0", 2) == strtol("0", NULL, 2));
//     assert(my_atoi_base("1", 2) == strtol("1", NULL, 2));
//     assert(my_atoi_base("10", 2) == strtol("10", NULL, 2));
//     assert(my_atoi_base("100", 2) == strtol("100", NULL, 2));
//     assert(my_atoi_base("1000", 2) == strtol("1000", NULL, 2));
//     assert(my_atoi_base("-1", 2) == strtol("-1", NULL, 2));
//     assert(my_atoi_base("-10", 2) == strtol("-10", NULL, 2));
//     assert(my_atoi_base("-100", 2) == strtol("-100", NULL, 2));
//     assert(my_atoi_base("-1010", 2) == strtol("-1010", NULL, 2));
//     assert(my_atoi_base("-0101", 2) == strtol("-0101", NULL, 2));
//     assert(my_atoi_base("0", 16) == strtol("0", NULL, 16));
//     assert(my_atoi_base("1", 16) == strtol("1", NULL, 16));
//     assert(my_atoi_base("10", 16) == strtol("10", NULL, 16));
//     assert(my_atoi_base("fa0fabc", 16) == strtol("fa0fabc", NULL, 16));
//     assert(my_atoi_base("FA0FABC", 16) == strtol("FA0FABC", NULL, 16));
//     assert(my_atoi_base("FA0Fabc", 16) == strtol("FA0Fabc", NULL, 16));
//     assert(my_atoi_base("1000", 16) == strtol("1000", NULL, 16));
//     assert(my_atoi_base("-1", 16) == strtol("-1", NULL, 16));
//     assert(my_atoi_base("-10", 16) == strtol("-10", NULL, 16));
//     assert(my_atoi_base("-0a9faba", 16) == strtol("-0a9faba", NULL, 16));
//     assert(my_atoi_base("-0a9Faba", 16) == strtol("-0a9Faba", NULL, 16));
//     assert(my_atoi_base("-ff09", 16) == strtol("-ff09", NULL, 16));
//     printf("all tests passed");
// }
