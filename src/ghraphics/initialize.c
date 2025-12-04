/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbaya <anbaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:30:15 by anbaya            #+#    #+#             */
/*   Updated: 2025/12/04 17:57:22 by anbaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

int	compute_block_size(int win_w, int win_h, int map_w, int map_h)
{
	int	block_w;
	int	block_h;
	int	block_size;

	if (map_w <= 0 || map_h <= 0 || win_w <= 0 || win_h <= 0)
		return (1);
	block_w = win_w / map_w;
	block_h = win_h / map_h;
	if (block_w < block_h)
		block_size = block_w;
	else
		block_size = block_h;
	if (block_size < 1)
		block_size = 1;
	return (block_size);
}

void	init_textures(t_cube *game, t_textures *txt)
{
	game->textures[NORTH].img = mlx_xpm_file_to_image(game->mlx, txt->no,
			&game->textures[NORTH].width, &game->textures[NORTH].height);
	game->textures[SOUTH].img = mlx_xpm_file_to_image(game->mlx, txt->so,
			&game->textures[SOUTH].width, &game->textures[SOUTH].height);
	game->textures[EAST].img = mlx_xpm_file_to_image(game->mlx, txt->ea,
			&game->textures[EAST].width, &game->textures[EAST].height);
	game->textures[WEST].img = mlx_xpm_file_to_image(game->mlx, txt->we,
			&game->textures[WEST].width, &game->textures[WEST].height);
	game->textures[NORTH].data = mlx_get_data_addr(game->textures[NORTH].img,
			&game->textures[NORTH].bpp, &game->textures[NORTH].size_line,
			&game->textures[NORTH].endian);
	game->textures[SOUTH].data = mlx_get_data_addr(game->textures[SOUTH].img,
			&game->textures[SOUTH].bpp, &game->textures[SOUTH].size_line,
			&game->textures[SOUTH].endian);
	game->textures[EAST].data = mlx_get_data_addr(game->textures[EAST].img,
			&game->textures[EAST].bpp, &game->textures[EAST].size_line,
			&game->textures[EAST].endian);
	game->textures[WEST].data = mlx_get_data_addr(game->textures[WEST].img,
			&game->textures[WEST].bpp, &game->textures[WEST].size_line,
			&game->textures[WEST].endian);
}

int	draw_loop(t_data *data)
{
	t_player	*player;
	float		fraction;
	float		start_x;
	int			i;

	player = &data->game.player;
	mlx_destroy_image(data->game.mlx, data->game.img);
	data->game.img = mlx_new_image(data->game.mlx, WIDTH, HIGHT);
	data->game.img_start = mlx_get_data_addr(data->game.img, &data->game.bpp, &data->game.size_line,
			&data->game.endian);
	move_player(player, &data->game, data);
	fraction = PI / 3 / WIDTH;
	start_x = player->angle - (PI / 6);
	i = 0;
	draw_floor_and_ceiling(&data->game);
	while (i < WIDTH)
	{
		draw_line(player, &data->game, start_x, i);
		start_x += fraction;
		i++;
	}
	mlx_put_image_to_window(data->game.mlx, data->game.win, data->game.img, 0, 0);
	return (0);
}

int	init_game(t_data *data, char **map)
{
	t_player	*player;

	data->game.block_size = compute_block_size(WIDTH, HIGHT, MAP_NUM_COLS,
			MAP_NUM_ROWS);
	init_player(&data->game.player, data);
	data->game.map = map;
	data->game.floor_color = rgb_to_int(data->colors->floor[0],
			data->colors->floor[1], data->colors->floor[2]);
	data->game.ceiling_color = rgb_to_int(data->colors->ceiling[0],
			data->colors->ceiling[1], data->colors->ceiling[2]);
	data->game.mlx = mlx_init();
	data->game.win = mlx_new_window(data->game.mlx, WIDTH, HIGHT, "cube");
	data->game.img = mlx_new_image(data->game.mlx, WIDTH, HIGHT);
	init_textures(&data->game, data->textures);
	data->game.img_start = mlx_get_data_addr(data->game.img, &data->game.bpp,
			&data->game.size_line, &data->game.endian);
	mlx_put_image_to_window(data->game.mlx, data->game.win,
		data->game.img, 0, 0);
	return (0);
}
