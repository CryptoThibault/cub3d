/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_column.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:18:09 by tchalaou          #+#    #+#             */
/*   Updated: 2024/09/30 15:02:07 by achevron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_height(t_data *data, t_inter inter)
{
	//int	dist;
	int	height;

	//dist = //get_distance
	height = //get height
}

int	get_color(t_data *data, t_inter  inter)
{
	int	color;
}

void	render_column(t_data *data, t_inter inter, int ray)
{
	t_ipos	pos;
	int	height
	int	color;

	height = get_height;
	pos.y = -1;
	color = get_color();
	while (++pos.y < (data->win_size.y / 2 - height / 2)) {
		pos.x = -1;
		while (++pos.x < ray * RAY_SIZE + RAY_SIZE - 1)
			mlx_pixel_put();
	}
	
	while (++pos.y < (data->win_size.y / 2 + height / 2))
	{
		pos.x = -1;
		color = get_color();
		while (++pos.x < ray * RAY_SIZE + RAY_SIZE - 1)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, pos.x, pos.y, color);
	}
	color = get_color();
	while (++pos.y < data->win_size.y)
	{
		pos.x = -1;
		while (++pos.x < ray * RAY_SIZE + RAY_SIZE - 1)
			mlx_pixel_put();
	}
}
