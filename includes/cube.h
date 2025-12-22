/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbaya <anbaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:30:07 by anbaya            #+#    #+#             */
/*   Updated: 2025/12/04 17:57:22 by anbaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define WIDTH 960
#define HIGHT 640

#define A 97
#define S 115
#define D 100
#define W 119
#define ESC 65307
#define LEFT 65361
#define RIGHT 65363

#define PI 3.1415926535

#define NO_TEXTURE "./textures/no_wall.xpm"
#define SO_TEXTURE "./textures/so_wall.xpm"
#define EA_TEXTURE "./textures/ea_wall.xpm"
#define WE_TEXTURE "./textures/we_wall.xpm"

#include "../src/parsing/cube.h"
#include "mlx/mlx.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum e_wall_side
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}				t_wall_side;

typedef struct s_texture
{
	void		*img;
	char		*data;
	int			width;
	int			height;
	int			bpp;
	int			size_line;
	int			endian;
}				t_texture;

typedef struct player
{
	float		x;
	float		y;
	bool		key_up;
	bool		key_down;
	bool		key_left;
	bool		key_right;
	bool		turn_left;
	bool		turn_right;
	float		angle;
}				t_player;

typedef struct cube
{
	int			block_size;
	void		*mlx;
	void		*win;
	void		*img;
	t_player	player;
	char		**map;
	char		*img_start;
	int			bpp;
	int			size_line;
	int			endian;
	t_texture	textures[4];
	int			floor_color;
	int			ceiling_color;
}				t_cube;

typedef struct s_ray
{
	float		x;
	float		y;
	float		angle;
	t_wall_side	wall_side;
}				t_ray;

typedef struct s_position
{
	float		x;
	float		y;
}				t_position;

typedef struct s_data
{
	t_cube		game;
	t_colors	*colors;
	t_textures	*textures;
	t_player	*player;
	t_layer		*layer;
	t_config	*config;
}				t_data;

// Main game function
int				cube(t_config *config);

// Player functions
void			init_player(t_player *player, t_data *data);
void			move_player(t_player *player, t_cube *game);
void			key_up(t_player *player, t_cube *game);
void			key_down(t_player *player, t_cube *game);
void			key_left(t_player *player, t_cube *game);
void			key_right(t_player *player, t_cube *game);
float			fix_angle(t_player *player);
bool			is_valid_position(float x, float y, t_cube *game);

// Key hooks
int				key_press(int keycode, t_data *data);
int				key_release(int keycode, t_data *data);

// Game initialization and loop
int				init_game(t_data *data, t_config *config);
int				rgb_to_int(int r, int g, int b);
int				draw_loop(t_data *data);
char			**get_map(void);
void			init_textures(t_cube *game, t_textures *txt);

// Raycasting
void			cast_ray(t_player *player, t_ray *ray, t_cube *game);
bool			touch(float px, float py, t_cube *game);
void			determine_wall_side(t_position *current, t_position *prev,
					t_wall_side *wall_side, t_cube *game);
float			distance(float dx, float dy);
float			fixed_dist(t_player *player, t_ray *ray, t_cube *game);

// Rendering
void			draw_line(t_player *player, t_cube *game, float start_x, int i);
void			draw_wall_column(t_cube *game, t_ray *ray, float height, int i);
void			draw_floor_and_ceiling(t_cube *game);
void			put_pixel(int x, int y, int color, t_cube *game);
int				get_color(t_cube *game, t_ray *ray, float line_height,
					float pixel_pos);

// Cleanup
void			free_data(t_data *data);
int				close_window(t_data *data);