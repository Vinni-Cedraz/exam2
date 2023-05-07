#include <assert.h>
#include <stdlib.h>

static int is_whitespace(char c) {
    return (c == ' ' || ('\t' <= c && c <= '\r'));
}

static int    is_digit(char c)
{
    return ((c >= '0' && c <= '9'));
}

static int convert_recursively(char *a, unsigned int toi) {
    if (!*a || is_whitespace(*a) || !is_digit(*a)) return toi;
    int single_digit = *a - '0';
    toi = toi * 10 + single_digit;
    return convert_recursively(a + 1, toi);
}

int my_atoi(char *str) {
    while (is_whitespace(*str)) str++;
    int sign = *str == '-' ? -1 : 1;
    if (sign == -1 || *str == '+') str++;
    return (convert_recursively(str, 0) * sign);
}

#include <stdio.h>
int main() {
    assert(my_atoi("4") == 4);
    assert(my_atoi("  4") == 4);
    assert(my_atoi("  4  ") == 4);
    assert(my_atoi("  4  5") == 4);
    assert(my_atoi("1235") == 1235);
    assert(my_atoi("\r1235\n") == 1235);
    assert(my_atoi("  1235") == 1235);
    assert(my_atoi("0") == atoi("0"));
    assert(my_atoi("1") == 1);
    assert(my_atoi("-1") == -1);
    assert(my_atoi("-101") == -101);
    assert(my_atoi("-101") == -101);
    assert(my_atoi("-2147483648") == -2147483648);
    assert(my_atoi("2147483647") == 2147483647);
    assert(my_atoi("+123") == 123);
    assert(my_atoi("  +123") == 123);
	assert(my_atoi("123aa") == atoi("123aa"));
    assert(my_atoi("abc1") == atoi("abc1"));
    assert(my_atoi("	abc1") == atoi("	abc1"));
    assert(my_atoi("\n\rabc1") == atoi("\n\rabc1"));
    printf("All tests passed.");
}
