/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoir <anoir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 20:50:46 by anoir             #+#    #+#             */
/*   Updated: 2025/12/14 20:53:24 by anoir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	is_in_borther(int x, int y, char **map)
{
	if (map[y - 1][x] == ' ' || map[y + 1][x] == ' ' || map[y][x - 1] == ' '
		|| map[y][x + 1] == ' ')
		return (1);
	if (map[y - 1][x] == '\0' || map[y + 1][x] == '\0' || map[y][x - 1] == '\0'
		|| map[y][x + 1] == '\0')
		return (1);
	if (map[y - 1][x] == '\n' || map[y + 1][x] == '\n' || map[y][x - 1] == '\n'
		|| map[y][x + 1] == '\n')
		return (1);
	return (0);
}

int	player_position_check(int x, int y, t_config *config)
{
	if (x <= 0 || y <= 0 || is_in_borther(x, y, config->map))
		return (1);
	return (0);
}
