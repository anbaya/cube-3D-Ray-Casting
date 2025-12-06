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

static int	process_digit(char *line, int *i, char *num, int *j)
{
	while (line[*i] && (line[*i] >= '0' && line[*i] <= '9') && *j < 14)
		num[(*j)++] = line[(*i)++];
	if (line[*i] != ',' && line[*i] != '\0'
		&& line[*i] != '\n' && line[*i] != ' ' && line[*i] != '\t')
		return (0);
	return (1);
}

static int	process_comma(char *line, int *i, char *num, int *j)
{
	int	*comma_count;

	comma_count = (int *)((char *)j + sizeof(int));
	if (*comma_count >= 2)
		return (0);
	num[(*j)++] = ',';
	(*comma_count)++;
	(*i)++;
	return (1);
}

int	parse_color_values(char *line, int i, char *num, int *comma_count)
{
	int	j;

	j = 0;
	while (line[i])
	{
		if (!process_digit(line, &i, num, &j))
			return (0);
		if (line[i] == '\n' || line[i] == '\0')
			break ;
		skip_space(line, &i);
		if (line[i] == ',')
		{
			if (*comma_count >= 2)
				return (0);
			num[j++] = ',';
			(*comma_count)++;
			i++;
		}
		skip_space(line, &i);
	}
	num[j] = '\0';
	return (1);
}
