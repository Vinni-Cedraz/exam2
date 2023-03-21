#include <stdio.h>
#include <stdlib.h>

int *my_range(int start, int end) {
    if (start < end) {
        int *tmp = malloc(sizeof(int) * (end - start) + 1);
        int *arr = tmp;
        while ((start - 1) < end) *tmp++ = start++;
        return arr;
    } else if (start > end) {
        int *arr = malloc(sizeof(int) * (start - end) + 1);
        int *tmp = arr;
        while ((start + 1) > end) *tmp++ = start--;
        return arr;
    }
    int *arr = malloc(sizeof(int));
    *arr = 0;
    return (arr);
}

// int main(void) {
//     int a, b, count;
//     a = 5;
//     b = 5;
//     int *arr = my_range(a, b);
//     int *tmp = arr;
//     b = b > 0 ? b : -b;
//     if (a > b && b > 0) {
//         count = (a - b + 1);
//     } else {
//         count = b - a + 1;
//     }
//     while (count--) printf("%d ", *arr++);
//     free(tmp);
// }
