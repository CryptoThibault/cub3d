/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:19:56 by tchalaou          #+#    #+#             */
/*   Updated: 2024/09/27 15:21:41 by achevron         ###   ########.fr       */
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
