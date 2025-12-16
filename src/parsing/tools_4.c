/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbaya <anbaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:34:09 by anbaya            #+#    #+#             */
/*   Updated: 2025/10/30 11:36:57 by anbaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	is_map_char(char c)
{
	return (c == '0' || c == '1' || c == '2' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W' || c == ' ');
}

int	map_parsing(t_config *config, int i, int j)
{
	static int	space;

	if (i < 0 || j < 0 || i >= config->num_rows)
		return (0);
	if (j >= (int)ft_strlen(config->nap[i]))
		return (0);
	if (config->nap[i][j] == '1' || config->nap[i][j] == '@')
		return (0);
	if (config->nap[i][j] == ' ' || config->nap[i][j] == '\t'
		|| config->nap[i][j] == '\n')
	{
		space = 1;
		return (1);
	}
	config->nap[i][j] = '@';
	map_parsing(config, i + 1, j);
	map_parsing(config, i - 1, j);
	map_parsing(config, i, j + 1);
	map_parsing(config, i, j - 1);
	if (space == 1)
		return (1);
	else
		return (0);
}

int	is_map(char *line)
{
	int	i;
	int	seen;

	if (!line)
		return (0);
	i = 0;
	seen = 0;
	while (line[i] && line[i] != '\n' && line[i] != '\r')
	{
		if (!is_map_char(line[i]))
			return (0);
		if (line[i] != ' ')
			seen = 1;
		i++;
	}
	return (seen);
}

char	**map_dup(t_config *config)
{
	int		i;
	char	**nap;

	nap = malloc(sizeof(char *) * (config->num_rows + 1));
	if (!nap)
		return (NULL);
	i = 0;
	while (config->map[i])
	{
		nap[i] = ft_strdup(config->map[i]);
		i++;
	}
	nap[i] = NULL;
	return (nap);
}

void	skip_space(char *line, int *i)
{
	while (line[*i] && (line[*i] == ' ' || line[*i] == '\t'))
		(*i)++;
	while (line[*i] && (line[*i] == 'F' || line[*i] == 'C'))
		(*i)++;
	while (line[*i] && (line[*i] == ' ' || line[*i] == '\t'))
		(*i)++;
}
