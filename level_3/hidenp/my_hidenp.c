#include <unistd.h>

static  int my_putstr(char *s) {
    while (s && *s) write(1, s++, 1);
    write(1, "\n", 1);
    return 0;
}

static  int it_is_there(char c, char *s2) {
    static int index;
    while (s2[index])
        if (c == s2[index++]) return 1;
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 3 || *argv[2] == '\0') {
        return (my_putstr("\n"));
    }
    char *str1 = argv[1];
    while (*str1)
        if (!it_is_there(*str1++, argv[2])) {
            return my_putstr("0");
        }
    my_putstr("1");
}
