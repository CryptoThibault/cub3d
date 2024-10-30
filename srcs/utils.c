/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:19:56 by tchalaou          #+#    #+#             */
/*   Updated: 2024/10/30 15:55:44 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_wall(t_data *data, t_fpos pos)
{
	return (data->map[(int)pos.y][(int)pos.x] == '1');
}

float	normalize_angle(float angle)
{
	float	normed_angle;

	normed_angle = angle;
	if (angle < 0)
		normed_angle += 2;
	if (angle >= 2)
		normed_angle -= 2;
	return (normed_angle);
}

int	is_in_map(t_data *data, t_fpos	pos)
{
	return (!!ft_strchr("01NSEW", data->map[(int)pos.y][(int)pos.x]));
}

int	get_frame(float angle)
{
	int	direction;

	direction = 0;
	if (angle >= 0 && angle < 0.5)//R down +x +y
		direction = 0;
	if (angle >= 0.5 && angle < 1)//L down -x +y
		direction = 1;
	if (angle >= 1 && angle < 1.5)//L up -x -y
		direction = 2;
	if (angle >= 1.5 && angle < 2)//R up +x -y
		direction = 3;
	return (direction);
}
