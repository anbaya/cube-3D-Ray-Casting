/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbaya <anbaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:30:15 by anbaya            #+#    #+#             */
/*   Updated: 2025/12/04 14:45:07 by anbaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

char	**get_map(void)
{
	char	**map;

	map = malloc(sizeof(char *) * 11);
	map[0] = "111111111111111";
	map[1] = "100000000000001";
	map[2] = "100000000000001";
	map[3] = "100000100000001";
	map[4] = "100000000000001";
	map[5] = "100000000000001";
	map[6] = "100001000000001";
	map[7] = "100000001100001";
	map[8] = "100000000000001";
	map[9] = "111111111111111";
	map[10] = NULL;
	return (map);
}

void	init_textures(t_cube *game)
{
	game->textures[NORTH].img = mlx_xpm_file_to_image(game->mlx, NO_TEXTURE,
			&game->textures[NORTH].width, &game->textures[NORTH].height);
	game->textures[SOUTH].img = mlx_xpm_file_to_image(game->mlx, SO_TEXTURE,
			&game->textures[SOUTH].width, &game->textures[SOUTH].height);
	game->textures[EAST].img = mlx_xpm_file_to_image(game->mlx, EA_TEXTURE,
			&game->textures[EAST].width, &game->textures[EAST].height);
	game->textures[WEST].img = mlx_xpm_file_to_image(game->mlx, WE_TEXTURE,
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

int	draw_loop(t_cube *game)
{
	t_player	*player;
	float		fraction;
	float		start_x;
	int			i;

	player = &game->player;
	mlx_destroy_image(game->mlx, game->img);
	game->img = mlx_new_image(game->mlx, WIDTH, HIGHT);
	game->img_start = mlx_get_data_addr(game->img, &game->bpp, &game->size_line,
			&game->endian);
	move_player(player, game);
	fraction = PI / 3 / WIDTH;
	start_x = player->angle - (PI / 6);
	i = 0;
	draw_floor_and_ceiling(game);
	while (i < WIDTH)
	{
		draw_line(player, game, start_x, i);
		start_x += fraction;
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}

int	init_game(t_cube *game)
{
	init_player(&game->player);
	game->map = get_map();
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HIGHT, "cube");
	game->img = mlx_new_image(game->mlx, WIDTH, HIGHT);
	init_textures(game);
	game->img_start = mlx_get_data_addr(game->img, &game->bpp, &game->size_line,
			&game->endian);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}
