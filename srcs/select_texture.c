/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:01:19 by tchalaou          #+#    #+#             */
/*   Updated: 2024/11/19 18:19:36 by achevron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	select_pixel(void *texture, int tex_x, int tex_y)
{
	t_img	img;
	int		pixel_pos;

	img.addr = (uint32_t *)mlx_get_data_addr(texture, &img.bpp,
		&img.bpl, &img.endian);
	pixel_pos = tex_y * img.bpl + tex_x * (img.bpp / 8);
	return (*(int *)((char *)img.addr + pixel_pos));
}

int	select_texture(t_fpos player_pos, t_inter inter)
{
	if (inter.orient && inter.pos.y <= player_pos.y)
		return (0);
	else if (inter.orient && inter.pos.y > player_pos.y)
		return (1);
	else if (!inter.orient && inter.pos.x <= player_pos.x)
		return (2);
	else if (!inter.orient && inter.pos.x > player_pos.x)
		return (3);
	else
		return (-1);
}
