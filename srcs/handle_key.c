/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:18:09 by achevron          #+#    #+#             */
/*   Updated: 2024/11/12 15:19:18 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_position(t_data *data, int xdir, int ydir, int *update)
{
	float	dir_radians;
	t_fpos	move;
	t_fpos	radius;

	dir_radians = data->player_dir * M_PI;
	move.x = (xdir * cos(dir_radians) - ydir * sin(dir_radians)) * SPEED;
	move.y = (xdir * sin(dir_radians) + ydir * cos(dir_radians)) * SPEED;	
	radius.x = RADIUS;
	radius.y = RADIUS;
	if (move.x < 0)
		radius.x = -RADIUS;
	if (move.y < 0)
		radius.y = -RADIUS;
	if (data->map[(int)data->player_pos.y]
		[(int)(data->player_pos.x + move.x + radius.x)] != '1')
		data->player_pos.x += move.x;
	if (data->map[(int)(data->player_pos.y + move.y + radius.y)]
		[(int)data->player_pos.x] != '1')
		data->player_pos.y += move.y;
	*update = 1;
}

void	update_direction(float *dir, float vel, int *update)
{
	if (*dir + vel < 0)
		*dir += 2;
	if (*dir + vel >= 2)
		*dir -= 2;
	*dir += vel;
	*update = 1;
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
