#include "so_long_bonus.h"

void	sprite_renew(t_sl *sl)
{
	renew_coll(sl);
	renew_player(sl);
	renew_enemy(sl);
	if (sl->coins == 0)
		sl->res->exit = sl->res->exiton;
}

void	draw_data(t_sl *sl)
{
	char	*str;

	str = ft_itoa(sl->moves);
    mlx_string_put(sl->mlx, sl->win, 0, SCALE / 2, 0x00FFFFFF, "MOVES: ");
    mlx_string_put(sl->mlx, sl->win, SCALE + (SCALE / 3), SCALE / 2, 0x00FFFFFF, str);
	free(str);
}

void	draw_player(t_sl *sl)
{
	mlx_put_image_to_window(sl->mlx, sl->win, sl->res->player,
		sl->px * SCALE, sl->py * SCALE);
}

void	draw_enemy(t_sl *sl)
{
	static int i;

	mlx_put_image_to_window(sl->mlx, sl->win, sl->res->enemy,
		sl->ex * SCALE, sl->ey * SCALE);
	if (i != sl->moves)
	{
		random_move_order(sl);
		i++;
	}
}

void	draw_map(t_sl *sl)
{
	int	i;
	int	j;

	i = 0;
	sprite_renew(sl);
	while (i < sl->map_height)
	{
		j = 0;
		while (j < sl->map_width)
		{
			if (sl->map[i][j] == 'P' || sl->map[i][j] == '0')
				mlx_put_image_to_window(sl->mlx, sl->win,
					sl->res->tile, j * SCALE, i * SCALE);
			else if (sl->map[i][j] == 'C')
				mlx_put_image_to_window(sl->mlx, sl->win,
					sl->res->coin, j * SCALE, i * SCALE);
			else if (sl->map[i][j] == '1')
				mlx_put_image_to_window(sl->mlx, sl->win,
					sl->res->wall, j * SCALE, i * SCALE);
			else if (sl->map[i][j] == 'E')
				mlx_put_image_to_window(sl->mlx, sl->win,
					sl->res->exit, j * SCALE, i * SCALE);
			j++;
		}
		i++;
	}
}
