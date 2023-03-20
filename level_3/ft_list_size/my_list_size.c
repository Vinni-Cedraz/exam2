#include <stdio.h>
#include <stdlib.h>

typedef struct s_list {
    struct s_list *next;
    void *data;
} t_list;

int my_list_size(t_list *begin_list) {
    if (begin_list == NULL) return (0);
    return (1 + my_list_size(begin_list->next));
}
