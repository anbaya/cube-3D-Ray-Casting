/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbaya <anbaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:38:04 by anbaya            #+#    #+#             */
/*   Updated: 2025/12/04 18:32:49 by anbaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	add_color(char *line, char *color, t_config *config, int index)
{
	int		i;
	int		rgb[3];
	char	**tmp;

	i = 0;
	tmp = ft_split(color, ',');
	if (!tmp)
		return (0);
	while (tmp[i])
		i++;
	if (i != 3)
	{
		while (i--)
			free(tmp[i]);
		return (free(tmp), free(color), 0);
	}
	rgb[0] = ft_atoi(tmp[0]);
	rgb[1] = ft_atoi(tmp[1]);
	rgb[2] = ft_atoi(tmp[2]);
	free(color);
	color_select(config, line, rgb, index);
	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	return (free(tmp), 1);
}
