#include <unistd.h>

int my_putchar(char c) { return (write(1, &c, 1)); }

int main(int argc, char *argv[]) {
    int i = 0;

    if (argc == 2) {
        while (argv[1][i]) i++;
        while (i) my_putchar(argv[1][--i]);
    }
    my_putchar('\n');
}
