/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerkiral <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:37:58 by yerkiral          #+#    #+#             */
/*   Updated: 2022/06/29 19:37:58 by yerkiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(char *str)
{
	int		len;
	int		index;
	char	*cpy;

	len = ft_strlen(str);
	index = 0;
	cpy = (char *) malloc(sizeof(char) * (len + 1));
	while (index < len)
	{
		cpy[index] = str[index];
		index++;
	}
	cpy[index] = '\0';
	return (cpy);
}

void	find_ents(t_sl *sl)
{
	int	i;
	int	j;

	i = 0;
	while (i < sl->map_height)
	{
		j = 0;
		while (j < sl->map_width)
		{
			if (sl->map[i][j] == 'P')
			{
				sl->px = j;
				sl->py = i;
			}
			j++;
		}
		i++;
	}
}

void	put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
}

void	ft_reset(char *buffer)
{
	int	i;

	i = 0;
	while (i < 10000)
		buffer[i++] = 0;
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
