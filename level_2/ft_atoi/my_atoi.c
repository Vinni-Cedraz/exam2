#include <stdio.h>
#include <stdlib.h>

static inline int how_mny_zeros(int diff);
static inline int is_whitespace(char c);
static inline int my_strlen(const char *str);
static inline int handle_negative(const char **str);
static inline int is_valid_number(const char(*str));

int my_atoi(const char *str) {
    int i = -1;
    int res = 0;
    if (!str) return 0;
    while (is_whitespace(*str)) str++;
    if (!is_valid_number(str)) return 0;
    int sign = handle_negative(&str);
    int len = my_strlen(str);
    while (++i < len) res += ((str[i] - '0') * how_mny_zeros(len - i - 1));
    return res * sign;
}

static inline int is_valid_number(const char(*str)) {
    while (*str && !is_whitespace(*str)) {
        if ((*str < '0' || *str > '9') && *str != '-' && *str != '+')
            return (0);
        str++;
    }
    return 1;
}

static inline int is_whitespace(char c) {
    return (c == ' ' || ('\t' <= c && c <= '\r'));
}

static inline int my_strlen(const char *str) {
    const char *end = str;
    while (*end && !is_whitespace(*end)) end++;
    return (end - str);
}

static inline int how_mny_zeros(int diff) {
    int res = 1;
    while (diff) {
        res *= 10;
        diff--;
    }
    return (res);
}

static inline int handle_negative(const char **str) {
    int sign = 1;
    if (**str == '-' || **str == '+') {
        if (**str == '-') sign = -1;
        (*str)++;
    }
    return (sign);
}

//
// #include <assert.h>
//
// int main() {
//   assert(my_atoi("4") == 4);
//   assert(my_atoi("  4") == 4);
//   assert(my_atoi("  4  ") == 4);
//   assert(my_atoi("  4  5") == 4);
//   assert(my_atoi("1235") == 1235);
//   assert(my_atoi("  1235") == 1235);
//   assert(my_atoi("0") == 0);
//   assert(my_atoi("1") == 1);
//   assert(my_atoi("-1") == -1);
//   assert(my_atoi("-101") == -101);
//   assert(my_atoi("-101") == -101);
//   assert(my_atoi("-2147483648") == -2147483648);
//   assert(my_atoi("2147483647") == 2147483647);
//   assert(my_atoi("+123") == 123);
//   assert(my_atoi("  +123") == 123);
//   assert(my_atoi("abc1") == atoi("abc1"));
//   printf("All tests passed.");
// }
