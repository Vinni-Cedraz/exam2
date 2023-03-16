/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 22:32:48 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/03/01 22:52:48 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include <stdio.h>


// static int putchar(char c)
// {
// 	return(write(1, &c, 1));
// }

static int is_odd(int c)
{
	if (c & 1)
	  return (1);
	return (0);
}

int main()
{
  int res;
  char num = '7';
  res = is_odd(num);
  printf("%d\n", res);
}
