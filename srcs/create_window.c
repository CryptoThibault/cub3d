#include "cub3d.h"

void	create_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if(!data->mlx_ptr)
		perror_exit("could not load mlx", data);
	mlx_get_screen_size(data->mlx_ptr, &data->win_size.x, &data->win_size.y);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_size.x / 2, data->win_size.y / 2, "cub3D");
	if (!data->win_ptr)
		perror_exit("could not create window", data);
	//data->map_tile.x = data->win_size.x / data->map_size.x;// AC
	//data->map_tile.y = data->win_size.y / data->map_size.y;// AC
}
