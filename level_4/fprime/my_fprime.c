#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av) {
    if (ac != 2) return (printf("\n"));

    int input = atoi(av[1]);
    int factor = 2;

    while (1) {
        while (0 == (input % factor)) {
            input /= factor;
            if (input == 1) break;
            printf("%d*", factor);
        }
        if (input == 1) break;
        factor++;
    }
    printf("%d", factor);
    printf("\n");
}
