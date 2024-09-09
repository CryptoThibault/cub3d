#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <stdio.h>

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
	char	*north_texture_path;
	char	*south_texture_path;
	char	*west_texture_path;
	char	*east_texture_path;
	int	floor_rgb[3];
	int	ceiling_rgb[3];
	char	**map;
	t_pos	size;
	t_pos	player_pos;
	float	direction;
}		t_data

typedef struct

#endif
