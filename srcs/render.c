/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:49:19 by achevron          #+#    #+#             */
/*   Updated: 2024/11/19 18:51:23 by achevron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_intersection(t_data *data, t_inter *inter, t_fpos step)
{
	while (is_in_map(data, inter->pos)
		&& data->map[(int)inter->pos.y][(int)inter->pos.x] != '1')
	{
		inter->pos.x += step.x;
		inter->pos.y += step.y;
	}
}

t_inter	vert_intersection(t_data *data, float angle, int frame)
{
	t_inter	inter;
	t_fpos	step;

	inter.pos.x = (int)data->player_pos.x;
	if (frame == 0 || frame == 3)
		inter.pos.x++;
	inter.pos.y = data->player_pos.y + (inter.pos.x - data->player_pos.x)
		* tan(angle * M_PI);
	if (frame == 1 || frame == 2)
		inter.pos.x--;
	step.x = 1;
	step.y = tan(angle * M_PI);
	if (frame == 1 || frame == 2)
		step.x *= -1;
	if ((frame == 2 || frame == 3) && step.y > 0)
		step.y *= -1;
	if ((frame == 0 || frame == 1) && step.y < 0)
		step.y *= -1;
	find_intersection(data, &inter, step);
	if (frame == 1 || frame == 2)
		inter.pos.x++;
	inter.orient = 0;
	inter.distance = get_distance(data->player_pos, inter.pos);
	return (inter);
}

t_inter	horiz_intersection(t_data *data, float angle, int frame)
{
	t_inter	inter;
	t_fpos	step;

	inter.pos.y = (int)data->player_pos.y;
	if (frame == 0 || frame == 1)
		inter.pos.y++;
	inter.pos.x = data->player_pos.x + (inter.pos.y - data->player_pos.y)
		/ tan(angle * M_PI);
	if (frame == 2 || frame == 3)
		inter.pos.y--;
	step.y = 1;
	step.x = 1 / tan(angle * M_PI);
	if (frame == 2 || frame == 3)
		step.y *= -1;
	if ((frame == 1 || frame == 2) && step.x > 0)
		step.x *= -1;
	if ((frame == 0 || frame == 3) && step.x < 0)
		step.x *= -1;
	find_intersection(data, &inter, step);
	if (frame == 2 || frame == 3)
		inter.pos.y++;
	inter.orient = 1;
	inter.distance = get_distance(data->player_pos, inter.pos);
	return (inter);
}

t_inter	raycast(t_data *data, float angle)
{
	int		frame;
	t_inter	vertical;
	t_inter	horizontal;

	frame = get_frame(angle);
	vertical = vert_intersection(data, angle, frame);
	horizontal = horiz_intersection(data, angle, frame);
	if (vertical.distance < horizontal.distance)
		return (vertical);
	else
		return (horizontal);
}

void	render(t_data *data)
{
	int		num_rays;
	int		ray;
	float	angle;
	t_inter	inter;

	num_rays = data->win_size.x / RAY_SIZE;
	ray = -1;
	while (++ray < num_rays)
	{
		angle = normalize_angle(data->player_dir - ((FOV / MAX_FOV) / 2)
				+ ((FOV / MAX_FOV) / num_rays) * ray);
		inter = raycast(data, angle);
		inter.distance *= cos((angle - data->player_dir) * M_PI);
		render_column(data, inter, ray);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
}
