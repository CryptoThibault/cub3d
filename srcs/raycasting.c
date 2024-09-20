
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
*/
float   vert_intersection(t_fpos player_pos, float ray_angle)
{
    return distance;
}

float   horiz_intersection(t_fpos player_pos, float ray_angle)
{
    return distance;
}
float	distance_to_wall(t_data *data, float ray_angle)
{
 	float   vert_distance;   
    float   horiz_distance;

    vert_distance = vert_intersection(data->player_pos, ray_angle);
    horiz_distance = horiz_intersection(data->player_pos, ray_angle);
    if (vert_distance <= horiz_distance)
        return (vert_distance);
    else
        return (horiz_distance);
}

void	raycasting(t_data	*data)
{
	int i;
	int	nb_of_rays;
	float ray_angle;
	float	ray_angle_incr;//de cbien s'incr le ray_angle entre chaq ray
	float	*ray_length;

	/*
	t_fpos	intersection_point;
	t_fpos	point;
	int	opposite;

	opposite = data->win_size.x / 2;
	*/

	nb_of_rays =  data->win_size.x / PIX_BTW_RAYS;
	ray_length = ft_calloc(nb_of_rays, sizeof (float));
	ray_angle = data->player_dir - (FOV /2);//1st, left most ray
	ray_angle_incr = FOV / nb_of_rays;
	i = 0;
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
		ray_length[i] = distance_to_wall(data, ray_angle);
		printf("distance to wall is : %f\n", ray_length[i]);
	//add angle_increment => ray moves to the right
		ray_angle += ray_angle_incr;//check angle conformity
		i++;
	}
}