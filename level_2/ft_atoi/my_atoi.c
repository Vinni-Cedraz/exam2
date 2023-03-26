static int is_whitespace(char c) {
    return (c == ' ' || ('\t' <= c && c <= '\r'));
}

static int is_valid_number(const char(*str)) {
    while (*str && !is_whitespace(*str)) {
        if ((*str < '0' || *str > '9') && *str != '-' && *str != '+')
            return (0);
        str++;
    }
    return 1;
}

static int convert_recursively(char *a, unsigned int toi) {
    if (!*a || is_whitespace(*a)) return toi;
    int single_digit = *a - '0';
    toi = toi * 10 + single_digit;
    return convert_recursively(a + 1, toi);
}

int my_atoi(char *str) {
    while (is_whitespace(*str)) str++;
	if (!is_valid_number(str)) return 0;
    int sign = *str == '-' ? -1 : 1;
    if (sign == -1 || *str == '+') str++;
    return (convert_recursively(str, 0) * sign);
}

// #include <assert.h>
// #include <stdio.h>
// int main() {
//     assert(my_atoi("4") == 4);
//     assert(my_atoi("  4") == 4);
//     assert(my_atoi("  4  ") == 4);
//     assert(my_atoi("  4  5") == 4);
//     assert(my_atoi("1235") == 1235);
//     assert(my_atoi("\r1235\n") == 1235);
//     assert(my_atoi("  1235") == 1235);
//     assert(my_atoi("0") == 0);
//     assert(my_atoi("1") == 1);
//     assert(my_atoi("-1") == -1);
//     assert(my_atoi("-101") == -101);
//     assert(my_atoi("-101") == -101);
//     assert(my_atoi("-2147483648") == -2147483648);
//     assert(my_atoi("2147483647") == 2147483647);
//     assert(my_atoi("+123") == 123);
//     assert(my_atoi("  +123") == 123);
//     assert(my_atoi("abc1") == atoi("abc1"));
//     assert(my_atoi("	abc1") == atoi("	abc1"));
//     assert(my_atoi("\n\rabc1") == atoi("\n\rabc1"));
//     printf("All tests passed.");
// }
