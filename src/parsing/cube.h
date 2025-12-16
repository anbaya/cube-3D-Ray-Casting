/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoir <anoir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:08:44 by anbaya            #+#    #+#             */
/*   Updated: 2025/12/14 20:54:42 by anoir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "get_next_line.h"
#include "libft.h"
#include "../../includes/mlx/mlx.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct textures
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
}				t_textures;

typedef struct s_player
{
	int			x;
	int			y;
	char		dir;
}				t_layer;

typedef struct colors
{
	int			floor[3];
	int			ceiling[3];
}				t_colors;

typedef struct s_config
{
	void		*mlx;
	char		**file;
	int			map_start;
	int			map_end;
	char		**map;
	char		**nap;
	int			p_x;
	int			p_y;
	char		p_dir;
	int			num_rows;
	int			row_length;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	int			no_i;
	int			so_i;
	int			we_i;
	int			ea_i;
	int			f_i;
	int			c_i;
	int			f_rgb[3];
	int			c_rgb[3];
	t_textures	*textures;
	t_colors	*colors;
	t_layer		*player;
}				t_config;

// cube main
int				cube(t_config *config);

// reading / loading
char			**read_file(char *filename);
int				file_loader(char **file, t_config *config);
char			**load_map(t_config *config, char **file);
int				load_textures(char **file, t_config *config);
int				load_colors(char **file, t_config *config);
char			**map_dup(t_config *config);
int				parse_file(char **file, t_config *config);
int				get_player(t_config *config, char **map);
int				player_position_check(int x, int y, t_config *config);
int				is_in_borther(int x, int y, char **map);
int				init_and_cleanup(int fd, char **sv);
int				is_player_char(char c);

// texture helpers
int				is_map(char *line);
int				is_texture(char *line);
int				parse_texture(t_config *config, char *line);
int				add_texture(char *line, t_config *config, int index);

// color helpers
int				is_color(char *line);
char			*read_color(char *line);
int				add_color(char *line, char *color, t_config *config, int index);
int				parse_color(t_config *config);
void			color_select(t_config *config, char *line, int *rgb, int index);
char			*c_reader(char *line, int i);
int				parse_color_values(char *line, int i,
					char *num, int *comma_count);

// generic utils
int				count_lines(int fd);
char			**copy_map(char **file, int start, int end);
void			skip_space(char *line, int *i);

// init
t_config		*init_config(char *filename);

// map parsing
int				map_parsing(t_config *config, int i, int j);
int				rows_check(char **map);
int				columns_check(char **map);
int				empty_check(char **map, int x, int y);
int				map_char_check(char **map);
int				fname_check(char *fname);

// bridge functions
t_textures		*bridge_textures(t_config *config);
t_colors		*bridge_colors(t_config *config);
t_layer			*bridge_player(t_config *config);

// memory management
void			free_config(t_config *config);
