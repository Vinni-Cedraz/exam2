#include <stddef.h>

int char_is_there(const char *s, int c) {
    while (*s) {
        if (*s == c) return 1;
        ++s;
    }
    return (0);
}

size_t my_strspn(const char *s, const char *accept) {
	const char *start = s;

    while (*s) {
        if (!char_is_there(accept, *s)) break;
		s++;
    }
    return (s - start);
}

// #include <assert.h>
// #include <stdio.h>
// #include <string.h>
// int main() {
//   	assert(strspn("hello_world", "hell") == my_strspn("hello_world", "hell"));
// 	assert(strspn("hello_world", "world") == my_strspn("hello_world", "world"));
//   	assert(strspn("hello_world", "hel") == my_strspn("hello_world", "hel"));
//   	assert(strspn("hello_world", "_") == my_strspn("hello_world", "_"));
//   	assert(strspn("hello_world", "    ") == my_strspn("hello_world", "    "));
//   	assert(strspn("hello_world", "hehabc") == my_strspn("hello_world", "hehabc"));
//   	assert(strspn("hello_world", "hello_banana_helloA") == my_strspn("hello_world", "hello_banana_helloA"));
//   	printf("all tests passed!\n");
// }
