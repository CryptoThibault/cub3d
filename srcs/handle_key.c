/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:18:09 by achevron          #+#    #+#             */
/*   Updated: 2024/11/19 18:16:43 by achevron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_data *data)
{
	int	closed;

	closed = mlx_loop_end(data->mlx_ptr);
	return (closed);
}

void	init_keylist(t_data *data)
{
	int	i;

	data->keylist[0] = XK_w;
	data->keylist[1] = XK_s;
	data->keylist[2] = XK_a;
	data->keylist[3] = XK_d;
	data->keylist[4] = XK_Left;
	data->keylist[5] = XK_Right;
	i = -1;
	while (++i < 6)
		data->keypress[data->keylist[i]] = 0;
}

int	handle_keypress(int keysym, t_data *data)
{
	int	i;

	if (keysym == XK_Escape)
		return (mlx_loop_end(data->mlx_ptr), 0);
	i = -1;
	while (++i < 6)
		if (!data->keypress[data->keylist[i]] && keysym == data->keylist[i])
			data->keypress[data->keylist[i]] = 1;
	return (0);
}

int	handle_keyrelease(int keysym, t_data *data)
{
	int	i;

	i = -1;
	while (++i < 6)
		if (keysym == data->keylist[i])
			data->keypress[data->keylist[i]] = 0;
	return (0);
}

int	handle_key(t_data *data)
{
	int	update;

	update = 0;
	if (data->keypress[XK_w])
		update_position(data, 1, 0, &update);
	if (data->keypress[XK_s])
		update_position(data, -1, 0, &update);
	if (data->keypress[XK_a])
		update_position(data, 0, -1, &update);
	if (data->keypress[XK_d])
		update_position(data, 0, 1, &update);
	if (data->keypress[XK_Left])
		update_direction(&data->player_dir, -VELOCITY, &update);
	if (data->keypress[XK_Right])
		update_direction(&data->player_dir, VELOCITY, &update);
	if (update)
		render(data);
	return (0);
}
