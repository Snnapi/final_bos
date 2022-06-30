#include "so_long_bonus.h"

void	renew_coll(t_sl *sl)
{
	static int i;

	if (!i)
		i = 5;
	if (i == 5)
		sl->res->coin = sl->res->coin1;
	else if (i == 10)
		sl->res->coin = sl->res->coin2;
	else if (i == 15)
		sl->res->coin = sl->res->coin3;
	else if (i == 20)
	{
		sl->res->coin = sl->res->coin4;
		i = 0;
	}
	i++;
}

void	renew_player(t_sl *sl)
{
	static int i;

	if (!i)
		i = 5;
	if (i == 5)
		sl->res->player = sl->res->player1;
	else if (i == 10)
	{
		sl->res->player = sl->res->player2;
		i = 0;
	}
	i++;
}

void	renew_enemy(t_sl *sl)
{
	static int i;

	if (!i)
		i = 5;
	if (i == 5)
		sl->res->enemy = sl->res->enemy1;
	else if (i == 10)
	{
		sl->res->enemy = sl->res->enemy2;
		i = 0;
	}
	i++;
}