#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void my_swap(char *a, char *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int my_strlen(char *s) {
    char *end = s;
    while (end && *end) end++;
    return end - s;
}

char *my_strrev(char *str) {
    int len = my_strlen(str);
    int end = len - 1;
    int i = -1;
    while (++i < len / 2) my_swap(&str[i], &str[end--]);
    return str;
}

// #include <assert.h>
// int main() {
//     char *str;
//
//     str = strdup("Hello World");
// 	printf("%s\n", my_strrev(str));
//     free(str);
//
//     str = strdup("World");
// 	printf("%s\n", my_strrev(str));
//     free(str);
//
//     str = strdup("");
// 	printf("%s\n", my_strrev(str));
//     free(str);
//
//     str = strdup("abcdefghijklmnopqrstuvxz");
// 	printf("%s\n", my_strrev(str));
//     free(str);
//
//     str = strdup("123456789");
// 	printf("%s\n", my_strrev(str));
//     free(str);
// }
