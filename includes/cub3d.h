/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:54:56 by tchalaou          #+#    #+#             */
/*   Updated: 2024/09/12 19:22:45 by tchalaou         ###   ########.fr       */
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

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_ipos	win_size;
	void	*textures[4];
	t_ipos	tex_size;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_rgb[3];
	int		ceiling_rgb[3];
	char	**map;
	t_fpos	map_size;
	t_fpos	player_pos;
	float	player_dir;
	int		keylist[6];
	int		keypress[65364];
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

#endif
