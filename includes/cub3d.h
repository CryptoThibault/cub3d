/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:54:56 by tchalaou          #+#    #+#             */
/*   Updated: 2024/09/10 13:33:53 by achevron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdint.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>

typedef struct s_pos
{
	float	x;
	float	y;
}		t_pos;

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*textures[4];
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_rgb[3];
	int		ceiling_rgb[3];
	char	**map;
	t_pos	size;
	t_pos	player_pos;
	float	direction;
}		t_data;

//main.c

//perror_exit.c
void	perror_exit(char *msg, t_data *data);
void	free_data(t_data *data);
void	free_array(char **array);
void	free_window(t_data *data);

//create_data.c
t_data	*create_data(char *infile);
void	create_map(int fd, t_data *data);
int		get_line_count(int fd);
int		*get_rgb(char *line, char *prefix);
char	*get_texture(char *line, char *prefix);

//win_manager.c
int		create_window(t_data *data);

//event_handlers.c


#endif
