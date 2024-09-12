/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:18:09 by achevron          #+#    #+#             */
/*   Updated: 2024/09/12 20:14:51 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_position(t_data *data, char c, float amount, int *render)
{
	if (c == 'y')
	{
	//	if (map[(int)(data->player_pos.y + amount) + PLAYER_RAD][(int)data->player_pos.x] != '1')
			data->player_pos.y += amount;
	}
	if (c == 'x')
	{
	//	if (map[(int)data->player_pos.y][(int)(data->player_pos.x + amount) + PLAYER_RAD] != '1')
			data->player_pos.x += amount;
	}
	*render = 1;
}

void	update_direction(float *dir, float amount, int *render)
{
	if (*dir + amount < 0)
		*dir += 2 * M_PI;
	if (*dir + amount >= 2 * M_PI)
		*dir -= 2 * M_PI;
	*dir += amount;
	*render = 1;
}

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
	int	render;

	render = 0;
	if (data->keypress[XK_w])
		update_position(data, 'y', -POS_MVT, &render);
	if (data->keypress[XK_s])
		update_position(data, 'y', POS_MVT, &render);
	if (data->keypress[XK_a])
		update_position(data, 'x', -POS_MVT, &render);
	if (data->keypress[XK_d])
		update_position(data, 'x', POS_MVT, &render);
	if (data->keypress[XK_Left])
		update_direction(&data->player_dir, -DIR_MVT, &render);
	if (data->keypress[XK_Right])
		update_direction(&data->player_dir, DIR_MVT, &render);
	if (render)
		update_screen(data);
	return (0);
}
