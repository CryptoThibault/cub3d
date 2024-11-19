/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:13:06 by achevron          #+#    #+#             */
/*   Updated: 2024/11/19 18:17:28 by achevron         ###   ########.fr       */
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
