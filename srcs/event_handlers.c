/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:18:09 by achevron          #+#    #+#             */
/*   Updated: 2024/09/10 18:30:06 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_loop_end(data->mlx_ptr);
	if (keysym == XK_Left)
		data->player_dir -= 0.1;
	if (keysym == XK_Right)
		data->player_dir += 0.1;
	if (keysym == XK_W || keysym == XK_w)
		data->player_pos.x += 0.1;
	if (keysym == XK_A || keysym == XK_a)
		data->player_pos.x -= 0.1;
	if (keysym == XK_S || keysym == XK_s)
		data->player_pos.y -= 0.1;
	if (keysym == XK_D || keysym == XK_d)
		data->player_pos.y += 0.1;
	else 
		return (0);
	//sys->need_update = true;
	return (0);
}

int	close_window(t_data *data)
{
	int	closed;

	closed = mlx_loop_end(data->mlx_ptr);
	return (closed);
}
