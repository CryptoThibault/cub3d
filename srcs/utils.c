/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:19:56 by tchalaou          #+#    #+#             */
/*   Updated: 2024/11/19 18:51:56 by achevron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	array_size(char **array)
{
	int	size;

	size = 0;
	while (array[size])
		size++;
	return (size);
}

int	get_line_count(int fd)
{
	char	*line;
	int		count;

	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		count++;
	}
	return (count);
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
	if (pos.x < 0 || pos.x >= data->map_size.x)
		return (0);
	if (pos.y < 0 || pos.y >= data->map_size.y)
		return (0);
	return (1);
}

float	get_distance(t_fpos a, t_fpos b)
{
	return (sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y)));
}
