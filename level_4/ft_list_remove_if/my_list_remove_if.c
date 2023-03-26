/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:42:56 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/26 15:43:05 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

// In short, the catch here is to do it in such a way that we can go through the
// nodes without changing the original list except when we have to remove a node

// recursive approach:
// Notice that the recursive function didnt require the creation of a second
// double pointer to the beginig of the list. This is because at the end of the
// recursive calls the initial address is preserved so the reference isnt lost.

// iterative approach:
// On the iterative approach we need a third variable that will point to the
// original list so that we can walk through the list without changing it. But
// we can also change the original list when necessary (that is, when removing a
// node); To change the original we derefence this third variable and to walk
// without changing the original we dont derefence.

typedef void *x; // to avoid compiler warnings while still fitting a singe line

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

void my_list_remove_if2(t_list **begin_list, void *data_ref, int (*cmp)(x, x)) {
    t_list **curr = begin_list;
    while (*curr) {
        if (!(*cmp)((*curr)->data, data_ref)) {
            t_list *to_rmv = *curr;
            *curr = (*curr)->next;
            free(to_rmv);
        } else
            curr = &(*curr)->next;
    }
}
