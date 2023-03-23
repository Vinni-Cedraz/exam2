#include <stdio.h>
#include <stdlib.h>

int *my_rrange(int start, int end) {
    if (end > start) {
        int *arr = malloc(sizeof(int) * (end - start) + 1);
        int *tmp = arr;
        while ((end + 1) != start) *tmp++ = end--;
        return arr;
    } else if (end < start) {
        int *arr = malloc(sizeof(int) * (start - end) + 1);
        int *tmp = arr;
        while ((end - 1) != start) *tmp++ = end++;
        return arr;
    } else {
        int *arr = malloc(sizeof(int) * 1);
        *arr = 0;
        return arr;
    }
}

// int main(void) {
//     int start, end, count;
//     start = -21;
//     end = 12;
//     int *arr = my_rrange(start, end);
//     int *tmp = arr;
//     end = end > 0 ? end : -end;
// 	count = start < end ? (end - start + 1): (start - end + 1);
//     if (count > 0)
//         while (count--) printf("%d ", *arr++);
//     else
//         printf("%d", *arr);
//     free(tmp);
// }
