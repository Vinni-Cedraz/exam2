#include <stdlib.h>
#include "ft_list.h"

void my_list_remove_if(t_list **begin_list, void *data_ref,
                       int (*cmp)(void *, void *)) {
    t_list *current = *begin_list;
    t_list *prev = NULL;
    while (current) {
        if (!cmp(current->data, data_ref)) {
            if (prev) {
                prev->next = current->next;
                free(current);
                current = prev->next;
            } else {
                *begin_list = current->next;
                free(current);
                current = *begin_list;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
}
