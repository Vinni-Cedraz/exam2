#include <unistd.h>

static void repeat_alpha(char c, int j);
static int how_many_times(char c);
static int my_putchar(char c) { return (write(1, &c, 1)); }

int main(int argc, char **argv) {
    char alpha = '*';
    int i = 0;

    if (argc != 2) return (my_putchar('\n'));
    while ((alpha = argv[1][i++])) repeat_alpha(alpha, how_many_times(alpha));
    my_putchar('\n');
}

static void repeat_alpha(char c, int j) {
    while (j--) my_putchar(c);
}

static int is_lower(char c) { return (c <= 122 && c >= 97); }
static int is_upper(char c) { return (c >= 65 && c <= 90); }

static int how_many_times(char c) {
    int times;

    if (is_upper(c))
        times = c - 64;
    else if (is_lower(c))
        times = c - 96;
    else
        times = 1;
    return (times);
}
