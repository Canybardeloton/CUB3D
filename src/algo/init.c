/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:32:01 by agiliber          #+#    #+#             */
/*   Updated: 2024/12/19 14:32:56 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_mlx_init(t_game_data *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("mlx_init fail");
	}
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, \
	SCREEN_HEIGHT, "raycaster");
	if (!game->win)
	{
		free(game->mlx);
		ft_printf("window launch fail");
	}
}

void	image_init(t_game_data *game)
{
	game->ray_img = mlx_new_image(game->mlx, 1920, 1080);
	game->ray_addr = mlx_get_data_addr(game->ray_img, &game->bpp, \
		&game->line_length, &game->endian);
	game->textures[0].img = mlx_xpm_file_to_image(game->mlx, \
		game->north_texture, &game->textures[0].width, \
		&game->textures[0].height);
	game->textures[1].img = mlx_xpm_file_to_image(game->mlx, \
		game->south_texture, &game->textures[1].width, \
		&game->textures[1].height);
	game->textures[2].img = mlx_xpm_file_to_image(game->mlx, \
		game->west_texture, &game->textures[2].width, \
			&game->textures[2].height);
	game->textures[3].img = mlx_xpm_file_to_image(game->mlx, \
		game->east_texture, &game->textures[3].width, \
		&game->textures[3].height);
	game->textures[4].img = mlx_xpm_file_to_image(game->mlx, \
		"textures/dark_oak_trapdoor.xpm", &game->textures[4].width, \
		&game->textures[4].height);
	game->textures[5].img = mlx_xpm_file_to_image(game->mlx, \
		"textures/obsidian.xpm", &game->textures[5].width, \
		&game->textures[5].height);
	game->textures[6].img = mlx_xpm_file_to_image(game->mlx, \
		"textures/suspicious_gravel_0.xpm", &game->textures[6].width, \
		&game->textures[6].height);
	image_verify(game);
}

void	image_init2(t_game_data *game)
{
	game->textures[0].addr = mlx_get_data_addr(game->textures[0].img, \
		&game->textures[0].bpp, &game->textures[0].line_length, \
		&game->textures[0].endian);
	game->textures[1].addr = mlx_get_data_addr(game->textures[1].img, \
		&game->textures[1].bpp, &game->textures[1].line_length, \
		&game->textures[1].endian);
	game->textures[2].addr = mlx_get_data_addr(game->textures[2].img, \
		&game->textures[2].bpp, &game->textures[2].line_length, \
		&game->textures[2].endian);
	game->textures[3].addr = mlx_get_data_addr(game->textures[3].img, \
		&game->textures[3].bpp, &game->textures[3].line_length, \
		&game->textures[3].endian);
	game->textures[4].addr = mlx_get_data_addr(game->textures[4].img, \
		&game->textures[4].bpp, &game->textures[4].line_length, \
		&game->textures[4].endian);
	game->textures[5].addr = mlx_get_data_addr(game->textures[5].img, \
		&game->textures[5].bpp, &game->textures[5].line_length, \
		&game->textures[5].endian);
	game->textures[6].addr = mlx_get_data_addr(game->textures[6].img, \
		&game->textures[6].bpp, &game->textures[6].line_length, \
		&game->textures[6].endian);
	addr_verify(game);
}

void	init_game(t_game_data *game)
{
	game->player.old_x = 0;
	game->player.old_y = 0;
	game->raycast.dirx = -1.0;
	game->raycast.diry = 0.0;
	game->raycast.planex = 0;
	game->raycast.planey = 0.66;
	game->raycast.posz = 0;
	game->raycast.deltadistx = 0;
	game->raycast.deltadisty = 0;
	game->raycast.sidedistx = 0;
	game->raycast.sidedisty = 0;
	game->raycast.perpwalldist = 0;
	game->raycast.hit = 0;
	game->raycast.door_state = 0;
	game->door_nbr = 0;
	game->north_texture = NULL;
	game->south_texture = NULL;
	game->west_texture = NULL;
	game->east_texture = NULL;
	game->ray_img = NULL;
	game->movespeed = 0;
	game->rotspeed = 0;
	init_game2(game);
}

void	init_game2(t_game_data *game)
{
	game->raycast.stepx = 0;
	game->raycast.stepy = 0;
	game->raycast.side = 0;
	game->raycast.time = 0;
	game->raycast.oldtime = get_time_in_seconds();
	game->raycast.delta_time = 1.0 / 60.0;
	game->raycast.pitch = 0;
	game->raycast.raydirx = 0;
	game->raycast.raydiry = 0;
	game->key.forward = 0;
	game->key.backward = 0;
	game->key.turn_left = 0;
	game->key.turn_right = 0;
	game->key.escape = 0;
	game->key.strafe_left = 0;
	game->key.strafe_right = 0;
	game->key_e_pressed = 0;
	game->floor_color = NULL;
	game->ceiling_color = NULL;
	game->map_height = 0;
	game->map_width = 0;
}
