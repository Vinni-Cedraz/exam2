#include <stdlib.h>

// notice that the recursive function didnt require the creating of a second
// double pointer to the beginig of the list. This is because at the end of the
// recursive calls the initial address is preserved so reference isnt lost.

#include "ft_list.h"

typedef void *x;

// // ==========================RECURSIVE APPROACH===========================//

void my_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(x, x)) {
    if (!*begin_list) return;
    if (!(*cmp)((*begin_list)->data, data_ref)) {
        t_list *tmp = *begin_list;
        *begin_list = (*begin_list)->next;
        free(tmp);
        my_list_remove_if(begin_list, data_ref, cmp);
    } else
        my_list_remove_if(&(*begin_list)->next, data_ref, cmp);
}

// // =========================ITERATIVE APPROACH============================//

// on the iterative approach we need a third variable that will point to the
// original list so that we can walk through the list without changing it. But
// we can also change the original list when necessary (that is, when removing a
// node); To change the original we derefence this third variable and to walk
// without changing the original we dont derefence.

// void my_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(x, x))
// {
//     t_list **curr = begin_list;
//     while (*curr) {
//         if (!(*cmp)((*curr)->data, data_ref)) {
//             t_list *to_rmv = *curr;
//             *curr = (*curr)->next;
//             free(to_rmv);
//         } else
//             curr = &(*curr)->next;
//     }
// }
