int my_max(int *tab, unsigned int len) {
  int max = 0;
  while (tab && len--) {
    if (*tab > max)
      max = *tab;
    tab++;
  }
  return (max);
}

//
// #include <math.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <strings.h>
//
// int main() {
//   int j = 0;
//   static uint i = 5;
//   int tab[99];
//
//   while (j < 99) {
//     i = (i >> 1) | (i << 31) ^ ((i >> 1) | (i << 31) ^ (i << 1));
//     tab[j] = i % 100;
//     j++;
//   }
//   while (j--)
//     printf("%d ", tab[j]);
//   printf("\n");
//   printf("\n");
//   int *empty = NULL;
//   printf("%d\n", my_max(tab, 45));
// }
