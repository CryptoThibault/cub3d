/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:54:56 by tchalaou          #+#    #+#             */
/*   Updated: 2024/09/10 15:36:31 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

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
	int	floor_rgb[3];
	int	ceiling_rgb[3];
	char	**map;
	t_pos	size;
	t_pos	player_pos;
	float	direction;
}		t_data;


t_data	*create_data(char *infile);
void	perror_exit(char *msg, t_data *data);
void	free_data(t_data *data);

#endif
