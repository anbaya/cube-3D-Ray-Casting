/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbaya <anbaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:30:37 by anbaya            #+#    #+#             */
/*   Updated: 2025/12/04 17:57:22 by anbaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	put_pixel(int x, int y, int color, t_cube *game)
{
	int	index;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HIGHT)
		return ;
	index = (y * game->size_line) + (x * (game->bpp / 8));
	game->img_start[index] = color & 0xFF;
	game->img_start[index + 1] = (color >> 8) & 0xFF;
	game->img_start[index + 2] = (color >> 16) & 0xFF;
	game->img_start[index + 3] = (color >> 24) & 0xFF;
}

void	draw_line(t_player *player, t_cube *game, float start_x, int i)
{
	t_ray	ray;
	float	dist;
	float	height;

	ray.angle = start_x;
	cast_ray(player, &ray, game);
	dist = fixed_dist(player, &ray, game);
	height = (game->block_size / dist) * (WIDTH / 2);
	draw_wall_column(game, &ray, height, i);
}

int	get_color(t_cube *game, t_ray *ray, float line_height, float pixel_pos)
{
	t_texture	*texture;
	float		wall_x;
	int			tex_x;
	int			tex_y;
	int			index;

	texture = &game->textures[ray->wall_side];
	if (ray->wall_side == NORTH || ray->wall_side == SOUTH)
		wall_x = ray->x;
	else
		wall_x = ray->y;
	wall_x = fmod(wall_x, (float)game->block_size);
	if (wall_x < 0)
		wall_x += game->block_size;
	tex_x = (int)(wall_x * texture->width / game->block_size);
	if (tex_x >= texture->width)
		tex_x = texture->width - 1;
	tex_y = (int)(pixel_pos * texture->height / line_height);
	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= texture->height)
		tex_y = texture->height - 1;
	index = (tex_y * texture->size_line) + (tex_x * (texture->bpp / 8));
	return (*(unsigned int *)(texture->data + index));
}

void	draw_wall_column(t_cube *game, t_ray *ray, float height, int i)
{
	int	start_y;
	int	end;

	start_y = (HIGHT - height) / 2;
	end = (start_y + height);
	while (start_y < end)
	{
		put_pixel(i, start_y, get_color(game, ray, height, start_y - (HIGHT
					- height) / 2), game);
		start_y++;
	}
}

void	draw_floor_and_ceiling(t_cube *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < HIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(x, y, game->ceiling_color, game);
			x++;
		}
		y++;
	}
	y = HIGHT / 2;
	while (y < HIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(x, y, game->floor_color, game);
			x++;
		}
		y++;
	}
}
