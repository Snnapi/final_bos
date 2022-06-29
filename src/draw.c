/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerkiral <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:25:21 by yerkiral          #+#    #+#             */
/*   Updated: 2022/06/29 19:27:33 by yerkiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_data(t_sl *sl)
{
	char	*str;

	str = ft_itoa(sl->moves);
	write(1, "MOVES: ", 7);
	put_str(str);
	free(str);
	write(1, "\n", 1);
}

void	draw_player(t_sl *sl)
{
	mlx_put_image_to_window(sl->mlx, sl->win, sl->res->player,
		sl->px * SCALE, sl->py * SCALE);
}

void	draw_map(t_sl *sl)
{
	int	i;
	int	j;

	i = 0;
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
