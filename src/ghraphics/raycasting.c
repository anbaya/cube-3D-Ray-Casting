/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbaya <anbaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:30:32 by anbaya            #+#    #+#             */
/*   Updated: 2025/12/04 17:37:34 by anbaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	determine_wall_side(t_position *current, t_position *prev,
		t_wall_side *wall_side, t_cube *game)
{
	int	x;
	int	y;
	int	prev_grid_x;
	int	prev_grid_y;

	x = current->x / game->block_size;
	y = current->y / game->block_size;
	prev_grid_x = prev->x / game->block_size;
	prev_grid_y = prev->y / game->block_size;
	if (prev_grid_x != x && current->x < prev->x)
		*wall_side = WEST;
	else if (prev_grid_x != x && current->x > prev->x)
		*wall_side = EAST;
	else if (prev_grid_y != y && current->y < prev->y)
		*wall_side = NORTH;
	else if (prev_grid_y != y && current->y > prev->y)
		*wall_side = SOUTH;
}

bool	touch(float px, float py, t_cube *game)
{
	int	x;
	int	y;

	x = px / game->block_size;
	y = py / game->block_size;
	if (game->map[y][x] == '1')
	{
		return (true);
	}
	return (false);
}

float	distance(float dx, float dy)
{
	return (sqrt(dx * dx + dy * dy));
}

float	fixed_dist(t_player *player, t_ray *ray, t_cube *game)
{
	float	delta_x;
	float	delta_y;
	float	angle;
	float	fix_dist;

	delta_x = ray->x - player->x;
	delta_y = ray->y - player->y;
	angle = atan2(delta_y, delta_x) - game->player.angle;
	fix_dist = distance(delta_x, delta_y) * cos(angle);
	return (fix_dist);
}

void	cast_ray(t_player *player, t_ray *ray, t_cube *game)
{
	t_position	current;
	t_position	prev;

	ray->x = player->x;
	ray->y = player->y;
	while (1)
	{
		prev.x = ray->x;
		prev.y = ray->y;
		ray->x += cos(ray->angle);
		ray->y += sin(ray->angle);
		if (touch(ray->x, ray->y, game))
		{
			current.x = ray->x;
			current.y = ray->y;
			determine_wall_side(&current, &prev, &ray->wall_side, game);
			break ;
		}
	}
}
