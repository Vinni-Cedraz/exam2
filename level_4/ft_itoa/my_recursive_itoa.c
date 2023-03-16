#include <stdlib.h>

static void recursively_build_ascii_string(int, char*, int*);
static int my_numlen(int);
static int handle_negative(int, char*, int*);

// ---------- MAIN FUNCTION ------------ //

char *my_recursive_itoa(int i) {
  char *ascii;
  int numlen;
  int j;

  j = 0;
  numlen = my_numlen(i);
  ascii = malloc(sizeof(char) * numlen + 1);
  i = handle_negative(i, ascii, &j);
  recursively_build_ascii_string(i, ascii, &j);
  if (i == 2147483647)
    ascii[numlen - 1] = '8';
  ascii[numlen] = '\0';
  return (ascii);
}

// --------- AUXILIARY FUNCTIONS ------------ //

static void recursively_build_ascii_string(int i, char *ascii, int *j) {
  if (i > 9)
    recursively_build_ascii_string(i / 10, ascii, j);
  ascii[(*j)++] = (i % 10) + '0';
}

static int handle_negative(int i, char *ascii, int *j) {
  if (i < 0) {
    ascii[*(j)] = '-';
    if (i == -2147483648)
      i++;
    i = -i;
    (*j)++;
  }
  return (i);
}

static int my_numlen(int nbr) {
  int i;

  i = 1;
  if (!nbr)
    return (1);
  if (nbr == -2147483648)
    nbr++;
  if (nbr < 0) {
    i++;
    nbr = -nbr;
  }
  while (nbr && i++)
    nbr /= 10;
  return (i - 1);
}

//
// ------------TESTS ---------------
//
// #include <assert.h>
// #include <stdio.h>
// #include <string.h>
// #include <unistd.h>
//
// int main(void) {
//   char *test;
//
//   test = my_recursive_itoa(1234);
//   assert(!strcmp("1234", test));
//   free(test);
//   test = my_recursive_itoa(87);
//   assert(!strcmp("87", test));
//   free(test);
//   test = my_recursive_itoa(9);
//   assert(!strcmp("9", test));
//   free(test);
//   test = my_recursive_itoa(0);
//   assert(!strcmp("0", test));
//   free(test);
//   test = my_recursive_itoa(-12);
//   assert(!strcmp("-12", test));
//   free(test);
//   test = my_recursive_itoa(-122);
//   assert(!strcmp("-122", test));
//   free(test);
//   test = my_recursive_itoa(-12999812);
//   assert(!strcmp("-12999812", test));
//   free(test);
//   test = my_recursive_itoa(-2147483648);
//   assert(!strcmp("-2147483648", test));
//   free(test);
//   printf("all tests passed!");
// }
