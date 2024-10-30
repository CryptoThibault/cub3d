/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:49:19 by achevron          #+#    #+#             */
/*   Updated: 2024/10/30 16:08:20 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
angle to deg = angle * 180
angle to rad = angle * M_PI

deg2rad = deg * (M_PI / 180)
rad2deg = rad * (180 / M_PI)

nb of rays : data.win_size.x / PIX_BTW_RAYS 
distance btw rays : ray_angle_incr = FOV / nb_of_rays

columns from 0 -> data.win_size.x - 1
rows from 0 -> data.win_size.y - 1

PYTHAGORE
angle = FOV / 2
opposite = data.win_size.x / 2

From left to right
	angle from [data.player_dir - (FOV /2)] to [data.player_dir + (FOV /2)]

VERTICAL = 0
HRIZONTAL = 1
*/
float	vert_intersection(t_data *data, t_inter	*inter, int frame)
{
	float	distance;
	t_fpos	step;
	t_fpos	cross_pt;
	float	angle;

	angle = normalize_angle(inter->angle);
	step.x = TILE_SIZE;
	step.y = angle * TILE_SIZE;
	
	if (((frame == 1 || frame == 2) && step.x > 0) 
		|| ((frame == 3 || frame == 0) && step.x < 0))
		step.x *= -1;
	step.y = TILE_SIZE;
	if (frame == 2 || frame == 3)
		step.y *= -1;
	
	cross_pt.x = data->player_pos.x + ((data->player_pos.y - cross_pt.y) / tan(angle));
	cross_pt.y = (floor(data->player_pos.y / TILE_SIZE)) * TILE_SIZE;	

	//printf("vert func / before while loop\n");
	while (!is_wall(data, cross_pt))
	{
		printf("vert func / in while loop\n");
		cross_pt.x += step.x;
		cross_pt.y += step.y;
	}
	inter->pos.x = cross_pt.x;
	inter->pos.y = cross_pt.y;
	printf("vertical intersection point is x : %f y: %f\n", cross_pt.x, cross_pt.y);
	distance = fabsf(inter->pos.y - data->player_pos.y) / (sin(angle));
	//printf("vertical distance : %f\n", distance);
	return distance;
}

float	horiz_intersection(t_data *data, t_inter *inter, int frame)
{
	float	distance;
	t_fpos	step;
	t_fpos	cross_pt;
	float	angle;

	angle = normalize_angle(inter->angle);
	step.x = TILE_SIZE / tan(angle);
	if (((frame == 1 || frame == 2) && step.x > 0) 
		|| ((frame == 3 || frame == 0) && step.x < 0))
		step.x *= -1;
	step.y = TILE_SIZE;
	if (frame == 2 || frame == 3)
		step.y *= -1;

	cross_pt.x = data->player_pos.x + ((data->player_pos.y - cross_pt.y) / tan(angle));
	cross_pt.y = (floor(data->player_pos.y / TILE_SIZE)) * TILE_SIZE;;
	
	//printf("horiz func / before while loop\n");
	while (!is_wall(data, cross_pt))
	{
		printf("horiz func / in while loop\n");
		cross_pt.x += step.x;
		cross_pt.y += step.y;
	}
	inter->pos.x = cross_pt.x;
	inter->pos.y = cross_pt.y;
	distance = fabsf(inter->pos.y - data->player_pos.y) / (sin(angle));
	printf("horizontal intersection point is x : %f y: %f\n", cross_pt.x, cross_pt.y);
	//printf("horizontal distance : %f\n", distance);
	return distance;
}

t_inter vert_intersection(t_data *data, float angle, int frame)
{
	t_inter	inter;

	return (inter);
}

t_inter horiz_intersection(t_data *data, float angle, int frame)
{
	t_inter	inter;

	return (inter);
}

t_inter	raycast(t_data *data, float angle)
{
	t_inter	vertical;
	t_inter	horizontal;
	int	frame;

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
	int		nb_of_rays;
	float	angle;
	float	incr;
	int		ray;
	t_inter	inter;


	nb_of_rays =  data->win_size.x / RAY_SIZE;
	printf("nb of rays : %d\n", nb_of_rays);
	angle = normalize_angle(data->player_dir - (FOV / 2));
	incr = FOV / nb_of_rays;
	ray = -1;
	while (++ray < nb_of_rays)
	{
		inter = raycast(data, angle);
		render_column(data, inter, ray);
		angle += incr;
		//printf("distance to wall is : %f\n", inter->distance);
	}
}
