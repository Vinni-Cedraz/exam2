#include <unistd.h>

void my_putstr(char *str) {
    while (str && *str) write(1, str++, 1);
}
