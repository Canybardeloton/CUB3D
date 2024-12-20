/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:32:01 by agiliber          #+#    #+#             */
/*   Updated: 2024/12/19 14:34:08 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height] != NULL)
		height++;
	return (height);
}

int	get_map_width(char **map)
{
	int	width;

	width = 0;
	if (map[0] != NULL)
		width = ft_strlen(map[0]);
	return (width);
}

void	init_doors(t_game_data *game)
{
	int	x;
	int	y;

	game->door_nbr = 0;
	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == 'P')
			{
				game->doors[game->door_nbr].x = x;
				game->doors[game->door_nbr].y = y;
				game->doors[game->door_nbr].state = 0;
				game->door_nbr++;
			}
			y++;
		}
		x++;
	}
}

void	handle_door(t_game_data *game)
{
	int	i;

	i = -1;
	while (++i < game->door_nbr)
	{
		if ((game->doors[i].x == game->player.mapx
				|| game->doors[i].x == game->player.mapx - 1
				|| game->doors[i].x == game->player.mapx + 1)
			&& (game->doors[i].y == game->player.mapy
				|| game->doors[i].y == game->player.mapy - 1
				|| game->doors[i].y == game->player.mapy + 1))
		{
			if (game->doors[i].state == 0)
			{
				game->map[game->doors[i].x][game->doors[i].y] = '2';
				game->doors[i].state = 1;
			}
			else if (game->doors[i].state == 1)
			{
				game->map[game->doors[i].x][game->doors[i].y] = 'P';
				game->doors[i].state = 0;
			}
			break ;
		}
	}
}
