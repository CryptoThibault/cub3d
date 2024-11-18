/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_column.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:18:09 by tchalaou          #+#    #+#             */
/*   Updated: 2024/11/18 18:05:14 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

	(void)data;
	buffer = mlx_get_data_addr(texture, &bpp, &size_line, &endian);
	pixel_pos = tex_y * size_line + tex_x * (bpp / 8);
	return (*(int *)(buffer + pixel_pos));
}

int	get_pixel_color(t_data *data, t_inter inter, int height, int tex_y)
{
	int	tex_id;
	int		tex_x;
	void	*texture;

	tex_id = select_texture(data->player_pos, inter);
	if (tex_id == -1)
		perror_exit("texture selection failed", data);
	if (inter.orient)
		tex_x = data->tex_size[tex_id].x * (inter.pos.x - (int)inter.pos.x);
	else
		tex_x = data->tex_size[tex_id].x * (inter.pos.y - (int)inter.pos.y);
	if (tex_id == 1 || tex_id == 2)
		tex_x = data->tex_size[tex_id].x - tex_x;
	tex_y = (tex_y * data->tex_size[tex_id].y) / height;
	texture = data->textures[tex_id];
	return (select_pixel(data, texture, tex_x, tex_y));
}

void	render_raw(t_data *data, int ray, t_ipos pos, int color)
{
	pos.x = ray * data->ray_size - 1;
	while (++pos.x < ray * data->ray_size + data->ray_size)
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, pos.x, pos.y, color);
}

void	render_column(t_data *data, t_inter inter, int ray)
{
	int		height;
	t_ipos	pos;
	int		color;

	height = data->win_size.y / inter.distance;
	pos.y = -1;
	color = rgb_to_int(data->ceiling_rgb);
	while (++pos.y < (data->win_size.y / 2 - height / 2))
		render_raw(data, ray, pos, color);
	pos.y--;
	while (++pos.y < (data->win_size.y / 2 + height / 2))
	{
		pos.x = ray * data->ray_size - 1;
		while (++pos.x < ray * data->ray_size + data->ray_size)
		{
			color = get_pixel_color(data, inter, height,
				pos.y - (data->win_size.y / 2 - height / 2));
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, pos.x, pos.y, color);
		}
	}
	color = rgb_to_int(data->floor_rgb);
	while (++pos.y < data->win_size.y)
		render_raw(data, ray, pos, color);
}
