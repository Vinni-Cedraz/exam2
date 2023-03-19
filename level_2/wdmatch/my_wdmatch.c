#include <unistd.h>

static inline void my_putstr(char *str) {
    while (str && *str) write(1, str++, 1);
}

static inline int is_it_there(char *str2, char c) {
    static int index;
    while (str2[index]) {
        if (str2[index] == c) return (1);
        index++;
    }
    return (0);
}

int main(int argc, char **argv) {
    int index = 0;
    char *res = argv[1];
    while (argc == 3 && argv[1] && *argv[1]) {
        index = is_it_there(argv[2], *argv[1]++);
    }
    if (index) my_putstr(res);
    my_putstr("\n");
}
