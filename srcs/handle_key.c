/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:18:09 by achevron          #+#    #+#             */
/*   Updated: 2024/09/13 17:08:56 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_position(t_data *data, int xdir, int ydir, int *render)
{
	t_fpos	move;

	move.x = (xdir * cos(data->player_dir) - ydir * sin(data->player_dir)) * SPEED;
	move.y = (xdir * sin(data->player_dir) + ydir * cos(data->player_dir)) * SPEED;	
	if (data->map[(int)data->player_pos.y][(int)(data->player_pos.x + move.x)] != '1')
		data->player_pos.x += move.x;
	if (data->map[(int)(data->player_pos.y + move.y)][(int)data->player_pos.x] != '1')
		data->player_pos.y += move.y;
	*render = 1;
}

void	update_direction(float *dir, float vel, int *render)
{
	if (*dir + vel < 0)
		*dir += 2;
	if (*dir + vel >= 2)
		*dir -= 2;
	*dir += vel;
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
		update_position(data, 0, -1, &render);
	if (data->keypress[XK_s])
		update_position(data, 0, 1, &render);
	if (data->keypress[XK_a])
		update_position(data, -1, 0, &render);
	if (data->keypress[XK_d])
		update_position(data, 1, 0, &render);
	if (data->keypress[XK_Left])
		update_direction(&data->player_dir, -VELOCITY, &render);
	if (data->keypress[XK_Right])
		update_direction(&data->player_dir, VELOCITY, &render);
	if (render)
		update_screen(data);
	return (0);
}
