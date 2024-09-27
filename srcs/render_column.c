/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_column.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:18:09 by tchalaou          #+#    #+#             */
/*   Updated: 2024/09/27 18:36:53 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_height(t_data *data, t_inter inter)
{
	int	dist;
	int	height;

	dist = //get_distance
	height = //get height
}

int	get_color(t_data *data, t_inter  inter)
{
	int	color;
}

void	render_column(t_data *data, t_inter inter, int ray)
{
	t_ipos	*pos;
	int	height
	int	color;

	pos.y = -1;
	while (++pos.y < data->win_size.y)
	{
		height = get_height(data, inter);
		if (height <= /*?*/)
			color = mlx_get_color_value(data->mlx_ptr);
		else if (height > /*?*/ && height < /*?*/)
			color = get_color(data);
		else if (height <= /*?*/)
			color = get_color(data);
		pos.x = ray * RAY_SIZE - 1;
		while (++pos.x < ray * RAY_SIZE + RAY_SIZE - 1)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, pos,x, pos.y, color);		
	}
}
