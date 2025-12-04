/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbaya <anbaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:09:23 by anbaya            #+#    #+#             */
/*   Updated: 2025/12/04 18:25:33 by anbaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	parse_color(t_config *config)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (config->f_rgb[i] < 0 || config->f_rgb[i] > 255)
			return (0);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (config->c_rgb[i] < 0 || config->c_rgb[i] > 255)
			return (0);
		i++;
	}
	return (1);
}

int	is_color(char *line)
{
	if (!line)
		return (0);
	if (ft_strnstr(line, "F ", 2) || ft_strnstr(line, "C ", 2))
		return (1);
	return (0);
}

char	*c_reader(char *line, int i)
{
	int		j;
	char	num[12];

	ft_strlcpy(num, "000,000,000", 12);
	j = 0;
	while (line[i])
	{
		while (line[i] && (line[i] >= '0' && line[i] <= '9') && j < 11)
			num[j++] = line[i++];
		if (line[i] != ',' && line[i] != '\0' && j != 8 && line[i] != '\n')
			return (0);
		if (line[i] == '\n')
			break ;
		if (j < 8)
			num[j++] = ',';
		if (line[i] == ',' && line[i + 1] != ',')
			i++;
		else
			return (NULL);
		skip_space(line, &i);
	}
	return (ft_strdup(num));
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
