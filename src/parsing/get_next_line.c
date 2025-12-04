/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbaya <anbaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:55:01 by anbaya            #+#    #+#             */
/*   Updated: 2025/10/30 11:09:00 by anbaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	freedom(char **new_sv, char **tmp)
{
	free(*new_sv);
	*new_sv = NULL;
	free(*tmp);
	*tmp = NULL;
}

char	*line_taker(char **sv)
{
	char	*tmp1;
	char	*tmp2;
	size_t	i;

	i = 0;
	while ((*sv)[i] != '\n' && (*sv)[i] != '\0')
		i++;
	tmp1 = ft_substr(*sv, 0, i + 1);
	i++;
	tmp2 = ft_substr(*sv, i, (ft_strlen(*sv) - i));
	free(*sv);
	*sv = tmp2;
	return (tmp1);
}

ssize_t	reader(int fd, char **sv, ssize_t buffer_sz)
{
	char	*tmp;
	ssize_t	ret;
	size_t	new_size;
	char	*new_sv;

	tmp = malloc(sizeof(char) * (buffer_sz + 1));
	if (!tmp)
		return (free(tmp), -1);
	ret = read(fd, tmp, buffer_sz);
	if (ret < 0)
		return (free(tmp), ret);
	tmp[ret] = '\0';
	new_size = (ft_strlen(*sv) + ret + 1);
	new_sv = malloc(sizeof(char) * new_size);
	if (!new_sv)
		return (free(new_sv), -1);
	ft_strlcpy(new_sv, *sv, ft_strlen(*sv) + 1);
	ft_strlcat(new_sv, tmp, ft_strlen(new_sv) + ft_strlen(tmp) + 1);
	free(*sv);
	*sv = malloc(sizeof(char) * new_size);
	if (!(*sv))
		return (free(*sv), -1);
	ft_strlcpy(*sv, new_sv, new_size + 1);
	freedom(&new_sv, &tmp);
	return (ret);
}

char	*last_line(char **sv)
{
	char	*last;

	last = malloc(ft_strlen(*sv) + 1);
	if (!last)
		return (free(last), NULL);
	ft_strlcpy(last, *sv, ft_strlen(*sv) + 1);
	free(*sv);
	*sv = NULL;
	return (last);
}

char	*get_next_line(int fd)
{
	static char	*sv;
	ssize_t		reader_return;

	if (!sv)
	{
		sv = malloc(1);
		sv[0] = '\0';
	}
	while (1)
	{
		if (ft_strchr(sv, '\n'))
			return (line_taker(&sv));
		else if (!(ft_strchr(sv, '\n')))
			reader_return = reader(fd, &sv, BUFFER_SIZE);
		if (reader_return <= 0)
		{
			if (reader_return == -1)
				return (free(sv), NULL);
			if (*sv)
				return (last_line(&sv));
			break ;
		}
	}
	free(sv);
	return (sv = NULL, NULL);
}
