/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:54:56 by tchalaou          #+#    #+#             */
/*   Updated: 2024/09/10 19:41:58 by tchalaou         ###   ########.fr       */
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
}		t_data;

//perror_exit.c
void	perror_exit(char *msg, t_data *data);
void	free_data(t_data *data);

//create_data.c
t_data	*create_data(char *infile);

void	check_map(t_data *data);

//win_manager.c
void	create_window(t_data *data);

void    load_textures(t_data *data);
//event_handlers.c

#endif
