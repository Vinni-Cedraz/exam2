#include "flood_fill.h"

static int			right_is_zone(char **tab, t_point, char, t_point);
static int			down_is_zone(char **tab, t_point, char, t_point);
static int			up_is_zone(char **tab, t_point, char, t_point);
static int			left_is_zone(char **tab, t_point, char, t_point);


//------------------------------MAIN-------------------------------------


void	recursive_flood_fill(char **tab, t_point size, t_point begin)
{
	char	to_replace;

	to_replace = tab[begin.y][begin.x];
	if (to_replace == 'F')
		return ;
	tab[begin.y][begin.x] = 'F';
	if (left_is_zone(tab, begin, to_replace, size))
		recursive_flood_fill(tab, size, (t_point){begin.x - 1, begin.y});
	if (up_is_zone(tab, begin, to_replace, size))
		recursive_flood_fill(tab, size, (t_point){begin.x, begin.y - 1});
	if (right_is_zone(tab, begin, to_replace, size))
		recursive_flood_fill(tab, size, (t_point){begin.x + 1, begin.y});
	if (down_is_zone(tab, begin, to_replace, size))
		recursive_flood_fill(tab, size, (t_point){begin.x, begin.y + 1});
}




//----------------------------------- AUXILIARY----------------------------------

static inline int	right_is_zone(char **tab, t_point cur, char c, t_point size){
	return (cur.x + 1 < size.x && tab[cur.y][cur.x + 1] == c);}
static inline int	down_is_zone(char **tab, t_point cur, char c, t_point size){
	return (cur.y + 1 < size.y && tab[cur.y + 1][cur.x] == c);}
static inline int	up_is_zone(char **tab, t_point cur, char c, t_point size){
	(void)size;
	return (cur.y - 1 >= 0 && tab[cur.y - 1][cur.x] == c);}
static inline int	left_is_zone(char **tab, t_point cur, char c, t_point size){
	(void)size;
	return (cur.x - 1 >= 0 && tab[cur.y][cur.x - 1] == c);}
