/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:19:56 by tchalaou          #+#    #+#             */
/*   Updated: 2024/11/12 17:45:19 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_wall(t_data *data, t_fpos pos)
{
	return (data->map[(int)pos.y][(int)pos.x] == '1');
}

float	normalize_angle(float angle)
{
	while (angle < 0)
		angle += 2;
	while (angle >= 2)
		angle -= 2;
	return (angle);
}

int	is_in_map(t_data *data, t_fpos pos)
{
	if (pos.x < 0 || pos.x > data->map_size.x)
		return (0);
	if (pos.y < 0 || pos.y > data->map_size.y)
		return (0);
	return (1);
}

int	get_frame(float angle)
{
	int	frame;

	if (angle >= 0 && angle < 0.5)
		frame = 0;
	if (angle >= 0.5 && angle < 1.0)
		frame = 1;
	if (angle >= 1.0 && angle < 1.5)
		frame = 2;
	if (angle >= 1.5 && angle < 2.0)
		frame = 3;
	return (frame);
}

float get_distance(t_fpos a, t_fpos b)
{
	return(sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y)));
}
