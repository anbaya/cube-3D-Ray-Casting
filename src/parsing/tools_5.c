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

int	init_and_cleanup(int fd, char **sv)
{
	if (fd < 0)
	{
		if (*sv)
			free(*sv);
		*sv = NULL;
		return (-1);
	}
	if (!(*sv))
	{
		*sv = malloc(1);
		if (!(*sv))
			return (-1);
		(*sv)[0] = '\0';
	}
	return (0);
}

char	*read_color(char *line)
{
	int	i;

	i = 0;
	skip_space(line, &i);
	if (!(line[i] >= '0' && line[i] <= '9'))
		return (NULL);
	return (c_reader(line, i));
}

void	color_select(t_config *config, char *line, int *rgb, int index)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] != 'F' && line[i] != 'C'))
		i++;
	if (line[i] == 'F')
	{
		config->f_rgb[0] = rgb[0];
		config->f_rgb[1] = rgb[1];
		config->f_rgb[2] = rgb[2];
		config->f_i = index;
	}
	else if (line[i] == 'C')
	{
		config->c_rgb[0] = rgb[0];
		config->c_rgb[1] = rgb[1];
		config->c_rgb[2] = rgb[2];
		config->c_i = index;
	}
}

char	*c_reader(char *line, int i)
{
	int		comma_count;
	char	num[15];

	ft_strlcpy(num, "", 15);
	comma_count = 0;
	if (!parse_color_values(line, i, num, &comma_count))
		return (NULL);
	if (comma_count != 2)
		return (NULL);
	return (ft_strdup(num));
}
