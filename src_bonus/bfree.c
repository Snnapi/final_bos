#include "so_long_bonus.h"

void	free_map_init(t_sl *sl)
{
	int	i;

	i = 0;
	while (i < sl->map_height)
		free(sl->map[i++]);
	free(sl->map);
	free(sl);
	write(1, "INVALID_MAP\n", 12);
	exit(1);
}

int	free_so_long(t_sl *sl)
{
	int	i;

	i = 0;
	while (i < sl->map_height)
		free(sl->map[i++]);
	free(sl->map);
	mlx_destroy_image(sl->mlx, sl->res->player1);
	mlx_destroy_image(sl->mlx, sl->res->player2);
	mlx_destroy_image(sl->mlx, sl->res->wall);
	mlx_destroy_image(sl->mlx, sl->res->coin1);
	mlx_destroy_image(sl->mlx, sl->res->coin2);
	mlx_destroy_image(sl->mlx, sl->res->coin3);
	mlx_destroy_image(sl->mlx, sl->res->coin4);
	mlx_destroy_image(sl->mlx, sl->res->tile);
	mlx_destroy_image(sl->mlx, sl->res->exiton);
	mlx_destroy_window(sl->mlx, sl->win);
	free(sl->res);
	free(sl);
	exit(1);
	return (0);
}
