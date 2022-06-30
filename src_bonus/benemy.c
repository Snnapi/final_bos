#include "so_long_bonus.h"

void	random_move_order(t_sl *sl)
{
	char	*ptr;
	long long a;

	ptr = malloc(sizeof(void *));
	a = ((long long ) ptr) % 7;
	if ((a == 0 || a == 3) && sl->map[sl->ey][sl->ex + 1] != '1')
		sl->ex++;
	else if ((a == 1 || a == 4) && sl->map[sl->ey + 1][sl->ex] != '1')
		sl->ey++;
	else if ((a == 2 || a == 5) && sl->map[sl->ey - 1][sl->ex] != '1')
		sl->ey--;
	else if ((a == 6) && sl->map[sl->ey][sl->ex - 1] != '1')
		sl->ex--;
	free(ptr);
}