
#include "cub3d.h"

void	update_screen(t_data *data)
{
	printf("[update screen] x: %f, y: %f dir: %f\n", data->player_pos.x,  data->player_pos.y,  data->player_dir);
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
