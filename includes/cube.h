/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbaya <anbaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:30:07 by anbaya            #+#    #+#             */
/*   Updated: 2025/12/04 13:30:07 by anbaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define WIDTH 960
#define HIGHT 640
#define BLOCK_SIZE 64 //TODO: adjust block size if needed
#define CELLING_COLOR 0x87CEEB
#define FLOOR_COLOR 0x228B22

#define A 97
#define S 115
#define D 100
#define W 119
#define ESC 65307
#define LEFT 65361
#define RIGHT 65363

#define PI 3.1415926535

#define no_texture "./textures/no_wall.xpm"
#define so_texture "./textures/so_wall.xpm"
#define ea_texture "./textures/ea_wall.xpm"
#define we_texture "./textures/we_wall.xpm"

#include "math.h"
#include "minilibx-linux/mlx.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

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

// Player functions
void			init_player(t_player *player);
void			move_player(t_player *player, t_cube *game);
void			key_up(t_player *player, t_cube *game);
void			key_down(t_player *player, t_cube *game);
void			key_left(t_player *player, t_cube *game);
void			key_right(t_player *player, t_cube *game);
float			fix_angle(t_player *player);
bool			is_valid_position(float x, float y, t_cube *game);

// Key hooks
int				key_press(int keycode, t_player *player);
int				key_release(int keycode, t_player *player);

// Game initialization and loop
int				init_game(t_cube *game);
int				draw_loop(t_cube *game);
char			**get_map(void);
void			init_textures(t_cube *game);

// Raycasting
void			cast_ray(t_player *player, t_ray *ray, t_cube *game);
bool			touch(float px, float py, t_cube *game, t_wall_side *wall_side);
void			determine_wall_side(t_position *current, t_position *prev,
					t_wall_side *wall_side);
float			distance(float dx, float dy);
float			fixed_dist(t_player *player, t_ray *ray, t_cube *game);

// Rendering
void			draw_line(t_player *player, t_cube *game, float start_x, int i);
void			draw_wall_column(t_cube *game, t_ray *ray, float height, int i);
void			draw_floor_and_ceiling(t_cube *game);
void			put_pixel(int x, int y, int color, t_cube *game);
int				get_color(t_cube *game, t_ray *ray, float line_height,
					float pixel_pos);