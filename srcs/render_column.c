/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_column.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:18:09 by tchalaou          #+#    #+#             */
/*   Updated: 2024/09/30 17:56:57 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_height(t_data *data, t_inter inter)
{
	int	height;

	height = data->win_size.y;
	height *= cos(inter.angle);
	return height;
}

int	get_color(int rgb[3])
{
	uint8_t	bytes[3];
	uint32_t color;

	bytes[0] = (uint8_t)rgb[0];
	bytes[1] = (uint8_t)rgb[1];
	bytes[2] = (uint8_t)rgb[2];
	color = 0 | (bytes[0] << 8) | (bytes[1] << 16) | (bytes[2] << 24);
	return ((int)color);
}

int	select_pixel(t_data *data, t_inter inter, int height, int tex_y)
{
	int	tex_x;
	void	*texture;
	uint32_t color;

	if (inter.orient)
		tex_x = inter.pos.x / height;
	else
		tex_x = inter.pos.y / height;
	texture = data->textures[select_texture(data->player_dir, inter.orient)];
	color = texture[TILE_SIZE * tex_x + tex_y];
	return ((int)color);
}

void	render_raw(t_data *data, int ray, t_ipos pos, int color)
{
		pos.x = ray * RAY_SIZE;
		while (pos.x < ray * RAY_SIZE + RAY_SIZE)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, pos.x++, pos.y++, color);
}

void	render_column(t_data *data, t_inter inter, int ray)
{
	t_ipos	pos;
	int	height;
	int	color;

	height = get_height(data, inter);
	pos.y = 0;
	color = get_color(data->ceiling_rgb);
	while (pos.y < (data->win_size.y / 2 - height / 2))
		render_raw(data, ray, pos, color);
	while (pos.y < (data->win_size.y / 2 + height / 2))
	{
		color = select_pixel(data, inter, height, pos.y - (data->win_size.y / 2 + height / 2))
		render_raw(data, ray, pos, color);
	}
	color = get_color(data->floor_rgb);
	while (pos.y < data->win_size.y)
		render_raw(data, ray, pos, color);
}
