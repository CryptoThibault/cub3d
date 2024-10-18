/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:49:19 by achevron          #+#    #+#             */
/*   Updated: 2024/10/18 16:56:43 by tchalaou         ###   ########.fr       */
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

void	raycast(t_data *data, t_inter *inter, int i)
{
	float	vert_distance;
	float	horiz_distance;
	int		frame;

	(void)i;
	frame = orientation(inter->angle);
	vert_distance = vert_intersection(data, inter, frame);
	horiz_distance = horiz_intersection(data, inter, frame);
	if (vert_distance <= horiz_distance)
	{
		inter->distance = vert_distance;
		inter->orient = 0;
	}
	else
	{
		inter->distance = horiz_distance;
		inter->orient = 1;
	}
}

void	render(t_data	*data)
{
	int		i;
	int		nb_of_rays;
	float	ray_angle_incr;//de cbien s'incr le inter->angle entre chaq ray
	t_inter	*inter;//ray that we cast


	nb_of_rays =  data->win_size.x / RAY_SIZE;
	inter = malloc(sizeof(t_inter));
	if (!inter)
		perror_exit("inter struct allocation failed", data);
	inter->angle = normalize_angle(data->player_dir - (FOV / 2));
	ray_angle_incr = FOV / nb_of_rays;
	i = 0;
	printf("nb of rays : %d\n", nb_of_rays);
	while (i < nb_of_rays)
	{
		/*
		point.x = data->player_pos.x;
		point.y = data->player_pos.y;
		//cast a ray
		//trace ray until intersects a wall (map[y][x] == 1 )
		//on update point en fonction de la direction = go en avant avec new dir
			while (data->map[(int)point.y][(int)point.x] != 1)
				//on projette le rayon
		//record intersection point (x,y)
			if (data->map[(int)point.y][(int)point.x] == 1)//should always hit a wall
			{
				//intersection_point.x = point.x;
				//intersection_point.y = point.y;
				intersection_point = point;
			}
		//compute distance to wall(ray length)
			if (ray_angle = data->player_dir)//or angle = 0 ?
				ray_length[column] = opposite / tan (ray_angle);//= adjacent
			else
				ray_length[column] = opposite / sin (ray_angle);//hypothenuse
		*/
	//compute length of ray
		raycast(data, inter, i);
		//printf("distance to wall is : %f\n", inter->distance);
	//render strip
		render_column(data, *inter, i);
	//add angle_increment => ray moves to the right
		inter->angle += ray_angle_incr;
		i++;
	}
	free(inter);
}
