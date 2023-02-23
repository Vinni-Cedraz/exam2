/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:15:19 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/25 23:10:53 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"
#include <stdio.h>

typedef struct s
{
	int y;
	int x;
}					t_p;

static int			right_is_zone(char **tab, t_p, char, t_point);
static int			down_is_zone(char **tab, t_p, char, t_point);
static int			up_is_zone(char **tab, t_p, char, t_point);
static int			left_is_zone(char **tab, t_p, char, t_point);

//-------------------------------------------------------------------------
//---------------------------------MAIN------------------------------------

void	my_flood_fill(char **tab, t_point size, t_point begin)
{
	t_p		queue[size.x * size.y];
	char	to_be_filled;
	int		start;
	int 	end;
	t_p		cur;

	end = 1;
	start = -1;
	to_be_filled = tab[begin.y][begin.x];
	queue[0] = (t_p){.y = begin.y, .x = begin.x};
	printf("To be filled: %c\n", to_be_filled);
	printf("queue: (%d,%d)\n", queue[0].y, queue[0].x);
	while (++start < end)
	{
		for (int i = start+1; i < end; i++)
			printf("Point on queue: (%d,%d)\n", queue[i].y, queue[i].x);
		cur = queue[start];
		tab[cur.y][cur.x] = 'F';
		printf("Current point: (%d,%d)\n", cur.y, cur.x);
		if (down_is_zone(tab, cur, to_be_filled, size))
			queue[end++] = (t_p){.y = cur.y + 1, .x = cur.x};
		if (right_is_zone(tab, cur, to_be_filled, size))
			queue[end++] = (t_p){.y = cur.y, .x = cur.x + 1};
		if (up_is_zone(tab, cur, to_be_filled, size))
			queue[end++] = (t_p){.y = cur.y - 1, .x = cur.x};
		if (left_is_zone(tab, cur, to_be_filled, size))
			queue[end++] = (t_p){.y = cur.y, .x = cur.x - 1};
	}
}

//-------------------------------------------------------------------------
//-------------------------------AUX---------------------------------------

static inline int	right_is_zone(char **tab, t_p cur, char c, t_point size)
{
	return (c != 'F' && cur.x + 1 < size.x && tab[cur.y][cur.x + 1] == c);
}
static inline int	down_is_zone(char **tab, t_p cur, char c, t_point size)
{
	return (c != 'F' && cur.y + 1 < size.y && tab[cur.y + 1][cur.x] == c);
}
static inline int	up_is_zone(char **tab, t_p cur, char c, t_point size)
{
	(void)size;
	return (c != 'F' && cur.y - 1 >= 0 && tab[cur.y - 1][cur.x] == c);
}
static inline int	left_is_zone(char **tab, t_p cur, char c, t_point size)
{
	(void)size;
	return (c != 'F' && cur.x - 1 >= 0 && tab[cur.y][cur.x - 1] == c);
}
