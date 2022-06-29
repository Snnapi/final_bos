#include "so_long_bonus.h"

static void	move_up(t_sl *sl)
{
	sl->py--;
	sl->moves++;
	if (sl->map[sl->py][sl->px] == 'C')
	{
		sl->map[sl->py][sl->px] = '0';
		sl->coins--;
	}
}

static void	move_left(t_sl *sl)
{
	sl->px--;
	sl->moves++;
	if (sl->map[sl->py][sl->px] == 'C')
	{
		sl->map[sl->py][sl->px] = '0';
		sl->coins--;
	}
}

static void	move_down(t_sl *sl)
{
	sl->py++;
	sl->moves++;
	if (sl->map[sl->py][sl->px] == 'C')
	{
		sl->map[sl->py][sl->px] = '0';
		sl->coins--;
	}
}

static void	move_right(t_sl *sl)
{
	sl->px++;
	sl->moves++;
	if (sl->map[sl->py][sl->px] == 'C')
	{
		sl->map[sl->py][sl->px] = '0';
		sl->coins--;
	}
}

int	key_event(int id, t_sl *sl)
{
	if (id == ESC)
		free_so_long(sl);
	else if (id == W_KEY && sl->map[sl->py - 1][sl->px] != '1')
		move_up(sl);
	else if (id == A_KEY && sl->map[sl->py][sl->px - 1] != '1')
		move_left(sl);
	else if (id == S_KEY && sl->map[sl->py + 1][sl->px] != '1')
		move_down(sl);
	else if (id == D_KEY && sl->map[sl->py][sl->px + 1] != '1')
		move_right(sl);
	if (sl->map[sl->py][sl->px] == 'E' && !sl->coins)
		free_so_long(sl);
	return (0);
}
