/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:54:56 by tchalaou          #+#    #+#             */
/*   Updated: 2024/11/06 17:20:28 by achevron         ###   ########.fr       */
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
# define BAR_SIZE 30
# define RADIUS 0.2
# define SPEED 0.1
# define VELOCITY 0.1
# define FOV 1.0/3.0
# define NUM_RAYS 192

typedef struct	s_ipos
{
	int	x;
	int	y;
}		t_ipos;

typedef struct	s_fpos
{
	float	x;
	float	y;
}		t_fpos;

typedef struct s_inter
{
	t_fpos	pos;
	int		orient;
	float	angle;
	float	distance;
}		t_inter;

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
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
	char	**map;
	t_ipos	map_size;
	t_fpos	player_pos;
	float	player_dir;
	int		keylist[6];
	int		keypress[XK_Right + 1];
	int		ray_size;
}		t_data;

void	perror_exit(char *msg, t_data *data);
void	free_data(t_data *data);
void	free_array(char **array);
t_data	*create_data(char *infile);
void	check_map(t_data *data);
void	create_window(t_data *data);
void    load_textures(t_data *data);
void	run_game(t_data *data);
void	update_screen(t_data *data);
void	init_keylist(t_data *data);
int		handle_key(t_data *data);
int		handle_keypress(int keysym, t_data *data);
int		handle_keyrelease(int keysym, t_data *data);
int		close_window(t_data *data);
float	normalize_angle(float angle);
int		is_wall(t_data *data, t_fpos pos);
int		is_in_map(t_data *data, t_fpos	pos);
int		get_frame(float angle);
float get_distance(t_fpos a, t_fpos b);
int	select_texture(float dir, int ori);
void	render(t_data *data);
void	render_column(t_data *data, t_inter inter, int ray);

#endif
