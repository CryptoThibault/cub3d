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

	// Get wall height from $inter.distance, win_size.y and
	// $data->tex_size[select_texture(data->player_dir, inter_orient)]
	height = TILE_SIZE;
	height *= cos(inter.angle); // Remove rounded perception
	return height;
}

int	rgb_to_int(int rgb[3])
{
	int color;

	color = 0;
	color |= (rgb[2] & 0xFF); 
	color |= (rgb[1] & 0xFF) << 8;
	color |= (rgb[0] & 0xFF) << 16;
	color |= 0xFF << 24;
	return (color);
}

int	select_pixel(t_data *data, void *texture, int tex_x, int tex_y)
{
	int	bpp;
	int	size_line;
	int	endian;
	char	*buffer;
	int	pixel_pos;

	buffer = mlx_get_data_addr(texture, &bpp, &size_line, &endian);
	pixel_pos = ((y * tex_y) / data->win_y) * size_line
		+ ((x * tex_x) / (data->win_x / 2)) * (bpp / 8);
	return (*(int *)(data + pixel_pos));
}

int	get_pixel_color(t_data *data, t_inter inter, int height, int tex_y)
{
	int		tex_x;
	void	*texture;
	int		color;

	if (inter.orient)
		tex_x = inter.pos.x / height;
	else
		tex_x = inter.pos.y / height;
	texture = data->textures[select_texture(data->player_dir, inter.orient)];
	return (select_color(data, texture, tex_x, tex_y));
}

void	render_raw(t_data *data, int ray, t_ipos pos, int color)
{
	pos.x = ray * RAY_SIZE - 1;
	while (++pos.x < ray * RAY_SIZE + RAY_SIZE)
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, pos.x, pos.y, color);
}

void	render_column(t_data *data, t_inter inter, int ray)
{
	int		height;
	t_ipos	pos;
	int		color;

	height = get_height(data, inter);
	pos.y = -1;
	color = rgb_to_int(data->ceiling_rgb);
	while (++pos.y < (data->win_size.y / 2 - height / 2) - 1)
		render_raw(data, ray, pos, color);
	while (++pos.y < (data->win_size.y / 2 + height / 2))
	{
		color = get_pixel_color(data, inter, height,
			pos.y - (data->win_size.y / 2 + height / 2));
		render_raw(data, ray, pos, color);
	}
	color = rgb_to_int(data->floor_rgb);
	while (++pos.y < data->win_size.y)
		render_raw(data, ray, pos, color);
}
