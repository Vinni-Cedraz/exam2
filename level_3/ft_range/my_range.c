#include <stdio.h>
#include <stdlib.h>

int *my_range(int start, int end) {
    if (start < end) {
        int *tmp = malloc(sizeof(int) * (end - start) + 1);
        int *arr = tmp;
        while ((start - 1) < end) *tmp++ = start++;
        return arr;
    } else if (end < 0) {
        int *arr = malloc(sizeof(int) * (-end - -start) + 1);
        int *tmp = arr;
        while ((start + 1) > end) *tmp++ = start--;
        return arr;
    }
    int *arr = malloc(sizeof(int));
    *arr = 0;
    return (arr);
}

// int main(void) {
//     int a, b;
//     a = -2;
//     b = 2;
//     int *arr = my_range(a, b);
//     int *tmp = arr;
//     b = b > 0 ? b : -b;
//     int count = b - a + 1;
//     if (count > 0)
//         while (count--) printf("%d ", *arr++);
//     else
//         printf("%d", *arr);
//     free(tmp);
// }
