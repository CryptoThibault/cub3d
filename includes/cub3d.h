/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:54:56 by tchalaou          #+#    #+#             */
/*   Updated: 2024/11/22 13:54:16 by achevron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define _USE_MATH_DEFINES
# define NUM_SCREEN 2
# define BAR_SIZE 0
# define WIN_RATIO 1
# define RADIUS 0.2
# define SPEED 0.1
# define VELOCITY 0.05
# define FOV 70.0
# define MAX_FOV 180.0
# define RAY_SIZE 1

typedef struct s_ipos
{
	int	x;
	int	y;
}		t_ipos;

typedef struct s_fpos
{
	float	x;
	float	y;
}		t_fpos;

typedef struct s_inter
{
	t_fpos	pos;
	int		orient;
	float	distance;
}		t_inter;

typedef struct s_img
{
	void		*mlx_img;
	uint32_t	*addr;
	int			bpp;
	int			bpl;
	int			endian;
}		t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_ipos	win_size;
	void	*textures[4];
	t_ipos	tex_size[4];
	char	**array;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_rgb[3];
	int		ceiling_rgb[3];
	char	**num_array;
	char	*char_list;
	char	**map;
	t_ipos	map_size;
	t_fpos	player_pos;
	float	player_dir;
	int		keylist[6];
	int		keypress[65364];
}		t_data;

void	perror_exit(char *msg, t_data *data);
void	free_data(t_data *data);
void	free_array(char **array);
t_data	*create_data(char *infile);
void	get_elements(t_data *data, char **array, t_ipos *pos);
int		ignore_whitespace(char **array, t_ipos *pos);
void	check_map(t_data *data);
void	create_window(t_data *data);
void	load_textures(t_data *data);
void	run_game(t_data *data);
void	init_keylist(t_data *data);
int		handle_key(t_data *data);
int		handle_keypress(int keysym, t_data *data);
int		handle_keyrelease(int keysym, t_data *data);
void	update_position(t_data *data, int xdir, int ydir, int *update);
void	update_direction(float *dir, float vel, int *update);
int		close_window(t_data *data);
float	normalize_angle(float angle);
int		array_size(char **array);
int		get_line_count(int fd);
int		is_in_map(t_data *data, t_fpos	pos);
float	get_distance(t_fpos a, t_fpos b);
int		get_frame(float angle);
int		select_pixel(void *texture, int tex_x, int tex_y);
int		select_texture(t_fpos player_pos, t_inter inter);
void	render(t_data *data);
void	render_column(t_data *data, t_inter inter, int ray);

#endif
