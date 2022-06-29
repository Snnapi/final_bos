#include "so_long_bonus.h"
#include <fcntl.h>

static void	hooker(t_sl *sl)
{
	mlx_hook(sl->win, 2, 1L << 0, key_event, sl);
	mlx_hook(sl->win, 17, 1L << 2, free_so_long, sl);
	mlx_loop_hook(sl->mlx, render, sl);
}

static t_sprite	*sprite_init(t_sl *game)
{
	t_sprite	*sprite;
	int			x;
	int			y;

	sprite = (t_sprite *) malloc(sizeof(t_sprite));
	sprite->wall = mlx_xpm_file_to_image(game->mlx, "res/wall.xpm", &x, &y);
	sprite->exit = mlx_xpm_file_to_image(game->mlx, "res/exit.xpm", &x, &y);
	sprite->tile = mlx_xpm_file_to_image(game->mlx, "res_bonus/tile.xpm", &x, &y);
	sprite->coin = mlx_xpm_file_to_image(game->mlx, "res_bonus/coin_b1.xpm", &x, &y);
	sprite->coin1 = mlx_xpm_file_to_image(game->mlx, "res_bonus/coin_b1.xpm", &x, &y);
	sprite->coin2 = mlx_xpm_file_to_image(game->mlx, "res_bonus/coin_b2.xpm", &x, &y);
	sprite->coin3 = mlx_xpm_file_to_image(game->mlx, "res_bonus/coin_b3.xpm", &x, &y);
	sprite->player = mlx_xpm_file_to_image(game->mlx, "res/player.xpm", &x, &y);
	return (sprite);
}

static void	map_init(t_sl *sl, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	sl->moves = 0;
	sl->coins = 0;
	sl->exit = 0;
	sl->ply = 0;
	sl->map = map_constractor(sl, fd);
	if (map_validation(sl))
		free_map_init(sl);
}

t_sl	*sl_init(char *path)
{
	t_sl	*sl;

	sl = (t_sl *) malloc(sizeof(t_sl));
	map_init(sl, path);
	find_ents(sl);
	sl->mlx = mlx_init();
	sl->win = mlx_new_window(sl->mlx,
			SCALE * sl->map_width, SCALE * sl->map_height, TITLE);
	sl->res = sprite_init(sl);
	hooker(sl);
	return (sl);
}
