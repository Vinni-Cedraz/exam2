int my_max(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

int my_min(int arr[], int n) {
    int smallest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < smallest) smallest = arr[i];
    }
    return smallest;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int arr[] = {1, 9, 2, 3, 4, -5, 7, 32, -45, 11, 87, 43, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int smallest = my_min(arr, n);
	int biggest = my_max(arr, n);
    int j = -1;

    j = -1;
    while (++j < n) printf("%d ", arr[j]);
    printf("\n");
    printf("\n");
    printf("%d\n", my_min(arr, n));
    printf("%d\n", my_max(arr, n));
}
