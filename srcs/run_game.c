
#include "cub3d.h"

void	update_screen(t_data *data)
{
	//int	nb_of_rays;
	//float ray_angle;
	//float	ray_angle_incr;//de cbien s'incr le ray_angle entre chaq ray
	//float	*ray_length;

	printf("[update screen] x: %f, y: %f dir: %f\n", data->player_pos.x,  data->player_pos.y,  data->player_dir);
	printf("[map size] x: %d, y: %d\n", data->map_size.x,  data->map_size.y);
//raycasting
	//nb_of_rays =  data->win_size.x / PIX_BTW_RAYS;
	//ray_length = ft_calloc(nb_of_rays, sizeof (float));
	//ray_angle = data->player_dir - (FOV /2);//check angle conformity //ray angle de depart : pr column = 0
	//ray_angle_incr = FOV / nb_of_rays;
	render(data);
//render
	//render(data);
	//free(ray_length);
}

void	run_game(t_data	*data)
{
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, &close_window, data);
	mlx_loop_hook(data->mlx_ptr, handle_key, data);
	update_screen(data);
	mlx_loop(data->mlx_ptr);
}
