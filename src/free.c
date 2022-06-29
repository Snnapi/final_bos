/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerkiral <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:28:28 by yerkiral          #+#    #+#             */
/*   Updated: 2022/06/29 20:22:18 by yerkiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	mlx_destroy_image(sl->mlx, sl->res->player);
	mlx_destroy_image(sl->mlx, sl->res->wall);
	mlx_destroy_image(sl->mlx, sl->res->coin);
	mlx_destroy_image(sl->mlx, sl->res->tile);
	mlx_destroy_image(sl->mlx, sl->res->exit);
	mlx_destroy_window(sl->mlx, sl->win);
	free(sl->res);
	free(sl);
	exit(1);
	return (0);
}
