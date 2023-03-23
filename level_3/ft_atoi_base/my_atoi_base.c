static int my_strlen(const char *s);
static int digit_value(char c);
static int my_pow(int base, int exp);

int my_atoi_base(const char *str, int str_base) {
    int pos = 0;
    int decimal = 0;
    int len = my_strlen(str) - 1;
    int sign = (*str == '-') ? -1 : 1;
    while (len + 1)
        decimal += digit_value(str[len--]) * my_pow(str_base, pos++);
    return (sign * decimal);
}

static int my_strlen(const char *s) {
    const char *end = s;
    while (end && *end) end++;
    return end - s;
}

static int digit_value(char c) {
    static const char s[] = {"0123456789abcdef"};
    int index = -1;
    while (s[++index])
        if (c == s[index]) return index;
    static const char s_up[] = {"0123456789ABCDEF"};
    index = -1;
    while (s_up[++index])
        if (c == s_up[index]) return index;
    return (-1);
}

static int my_pow(int base, int exp) {
    if (exp == 0) return 1;
    if (exp == 1) return base;
    int tmp = base;
    while (--exp) base *= tmp;
    return base;
}
