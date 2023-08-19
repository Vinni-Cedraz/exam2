#include <assert.h>
static void print_arr(int *arr, unsigned int n);

int my_max(int *arr, unsigned int n) {
    int max = arr[0];
    for (unsigned int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int my_min(int *arr, unsigned int n) {
    int smallest = arr[0];
    for (unsigned int i = 1; i < n; i++)
        if (arr[i] < smallest)
            smallest = arr[i];
    return smallest;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// int main(void) {
//     int static_arr[] = {1, 9, 2, 3, 4, -5, 7, 32, -45, 11, 87, 43, 6, 8};
//
//     int n1 = sizeof(static_arr);
//     int n2 = sizeof(static_arr[0]);
//     int number_of_elements = n1 / n2;
//
//     int smallest = my_min(static_arr, number_of_elements);
//     int biggest = my_max(static_arr, number_of_elements);
//
//     printf("n1 => %d\n", n1);
//     printf("n2 => %d\n", n2);
//
//     print_arr(static_arr, number_of_elements);
//     assert(biggest == 87);
//     assert(smallest == -45);
//
//     printf("all tests passed!\n");
// }
//
// static void print_arr(int *arr, unsigned int n) {
//     unsigned int j = -1;
//     while (++j < n)
//         printf("%d ", arr[j]);
//     printf("\n");
// }
