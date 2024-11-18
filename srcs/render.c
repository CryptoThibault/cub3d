/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:49:19 by achevron          #+#    #+#             */
/*   Updated: 2024/11/18 18:07:16 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_inter vert_intersection(t_data *data, float angle, int frame)
{
	t_inter	inter;
	t_fpos	step;

	inter.pos.x = (int)data->player_pos.x;
	if (frame == 0 || frame == 3)
		inter.pos.x++;	
	inter.pos.y = data->player_pos.y + (inter.pos.x - data->player_pos.x) * tan(angle * M_PI);
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
	while (is_in_map(data, inter.pos) && !is_wall(data, inter.pos))
	{
		inter.pos.x += step.x;
		inter.pos.y += step.y;
	}
	if (frame == 1 || frame == 2)
		inter.pos.x++;
	inter.orient = 0;
	inter.distance = get_distance(data->player_pos, inter.pos);
	return (inter);
}

t_inter horiz_intersection(t_data *data, float angle, int frame)
{
	t_inter	inter;
	t_fpos	step;

	inter.pos.y = (int)data->player_pos.y;
	if (frame == 0 || frame == 1)
		inter.pos.y++;
	inter.pos.x = data->player_pos.x + (inter.pos.y - data->player_pos.y) / tan(angle * M_PI);
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
	while (is_in_map(data, inter.pos) && !is_wall(data, inter.pos))
	{
		inter.pos.x += step.x;
		inter.pos.y += step.y;
	}
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
	float	angle;
	int		ray;
	t_inter	inter;

	data->ray_size = data->win_size.x / NUM_RAYS; 
	ray = -1;
	while (++ray < NUM_RAYS)
	{
		angle = normalize_angle(data->player_dir - (FOV / 2) + (FOV / NUM_RAYS) * ray);
		inter = raycast(data, angle);
		inter.distance *= cos((angle - data->player_dir) * M_PI);
		render_column(data, inter, ray);
	}
}
