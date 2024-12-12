#include "../../includes/cub3d.h"

void	init_mini_map(t_minimap *minimap, t_game_data *data)
{
	minimap->tile_size = 16;
	minimap->minimap_size = 10.0;
	minimap->map_offset_x = data->player.y - minimap->minimap_size / 2.0;
	minimap->map_offset_y = data->player.x - minimap->minimap_size / 2.0;
	minimap->player_minimap_x = (minimap->minimap_size / 2.0) \
	* minimap->tile_size;
	minimap->player_minimap_y = (minimap->minimap_size / 2.0) \
	* minimap->tile_size;
	minimap->pixel_y = 5;
}

void	init_minimap_2(t_minimap *minimap, int pixel_x, int pixel_y)
{
	minimap->world_x = minimap->map_offset_x \
	+ (double)pixel_x / minimap->tile_size;
	minimap->world_y = minimap->map_offset_y \
	+ (double)pixel_y / minimap->tile_size;
	minimap->map_x = (int)minimap->world_x;
	minimap->map_y = (int)minimap->world_y;
}

void	draw_minimap(t_game_data *data, t_minimap minimap, int pixel_x)
{
	if (data->map[minimap.map_y][minimap.map_x] == '1')
		my_mlx_pixel_put(data, pixel_x, minimap.pixel_y, 0x000000);
	else if (data->map[minimap.map_y][minimap.map_x] == '0' \
	|| data->map[minimap.map_y][minimap.map_x] == 'N')
		my_mlx_pixel_put(data, pixel_x, minimap.pixel_y, 0xFFFFFF);
	else
		my_mlx_pixel_put(data, pixel_x, minimap.pixel_y, 0x8B00FF);
}

void	minimap(t_game_data *data)
{
	t_minimap	minimap;
	int			pixel_x;

	init_mini_map(&minimap, data);
	while (++minimap.pixel_y < (minimap.minimap_size * minimap.tile_size) + 5)
	{
		pixel_x = 5;
		while (++pixel_x < (minimap.minimap_size * minimap.tile_size) + 5)
		{
			init_minimap_2(&minimap, pixel_x, minimap.pixel_y);
			if (minimap.map_y >= 0 && minimap.map_y < data->map_height \
			&& minimap.map_x >= 0 && minimap.map_x < data->map_width)
				draw_minimap(data, minimap, pixel_x);
			else
				my_mlx_pixel_put(data, pixel_x, minimap.pixel_y, 0x8B00FF);
		}
	}
	draw_player(data, minimap.player_minimap_x, minimap.player_minimap_y, \
	3, 0xFF0000);
}
