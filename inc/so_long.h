/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerkiral <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:57:45 by yerkiral          #+#    #+#             */
/*   Updated: 2022/06/29 20:22:42 by yerkiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"

# define SCALE 64
# define TITLE "so_long"

# define ESC 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2

typedef struct s_sprite
{
	void	*player;
	void	*coin;
	void	*wall;
	void	*tile;
	void	*exit;
}	t_sprite;

typedef struct s_sl
{
	void		*mlx;
	void		*win;

	int			map_height;
	int			map_width;
	char		**map;

	int			moves;
	int			coins;

	int			exit;
	int			ply;

	int			px;
	int			py;

	t_sprite	*res;
}	t_sl;

//RENDER
int		render(t_sl *sl);

//DRAW
void	draw_map(t_sl *sl);
void	draw_player(t_sl *sl);
void	draw_data(t_sl *sl);

//INIT.c
t_sl	*sl_init(char *path);

//MAP_CONSTRACTOR
char	**map_constractor(t_sl *sl, int fd);

//MAP_VALIDATION
int		map_validation(t_sl *sl);

//UTILS
void	find_ents(t_sl *sl);
void	ft_reset(char *buffer);
void	put_str(char *str);
int		ft_strlen(char *str);
char	*ft_itoa(int nbr);
char	*ft_strdup(char *str);

//FREE
void	free_map_init(t_sl *sl);
int		free_so_long(t_sl *sl);

//EVENT
int		key_event(int id, t_sl *sl);

#endif
