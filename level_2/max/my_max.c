int my_max(int *tab, unsigned int len) {
    int max = 0;
    while (tab && len--) {
        if (*tab > max) max = *tab;
        tab++;
    }
    return (max);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// int main() {
//     int j = -1;
// 	int len = 119;
//     int tab[len];
//
// 	srand(time(NULL));
// 	while (++j < len) tab[j++] = random() % len;
//     j = -1;
//     while (++j < len) printf("%d ", tab[j]);
//     printf("\n");
//     printf("\n");
//     printf("%d\n", my_max(tab, len));
// }
