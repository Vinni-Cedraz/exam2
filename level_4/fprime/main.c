#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
  int n;
  int i;

  if (argc != 2)
    return (printf("\n"));
  i = 2;
  n = atoi(argv[1]);
  while (i <= atoi(argv[1])) {
    if ((n % i) == 0) {
      n = n / i;
      if (n == 1)
        break;
      printf("%d*", i);
      i--;
    }
    i++;
  }
  printf("%d\n", i);
}
