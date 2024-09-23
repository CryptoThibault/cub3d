
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
float   vert_intersection(t_data *data, float ray_angle, t_ipos dir_factor)
{
	float	distance;
	t_fpos	step;
	t_fpos	intersection_pt;
	float	angle;

	angle = normalize_angle(ray_angle);
	//intersection_pt.y = (floor(player_pos.y / data->map_tile.y)) * data->map_tile.y;
	intersection_pt.y = (floor(data->player_pos.y / TILE_SIZE)) * TILE_SIZE;
	intersection_pt.x = data->player_pos.x + ((data->player_pos.y - intersection_pt.y) / tan(angle));
	step.x = dir_factor.x * (TILE_SIZE);
	step.y = dir_factor.y * ((angle) * TILE_SIZE);
	//printf("vert func / before while loop\n");
	while (is_in_map(data, intersection_pt) && !is_wall(data, intersection_pt))
	{
		printf("vert func / in while loop\n");
		intersection_pt.x += step.x;
		intersection_pt.y += step.y;
	}
	printf("vertical intersection point is x : %f y: %f\n", intersection_pt.x, intersection_pt.y);
	distance = fdim(intersection_pt.y, data->player_pos.y) / (sin(angle));
	//printf("vertical distance : %f\n", distance);
    return distance;
}

float   horiz_intersection(t_data *data, float ray_angle, t_ipos dir_factor)
{
	float	distance;
	t_fpos	step;
	t_fpos	intersection_pt;
	float	angle;

	angle = normalize_angle(ray_angle);
	//intersection_pt.y = (floor(player_pos.y / data->map_tile.y)) * data->map_tile.y;
	intersection_pt.y = (floor(data->player_pos.y / TILE_SIZE)) * TILE_SIZE;
	intersection_pt.x = data->player_pos.x + ((data->player_pos.y - intersection_pt.y) / tan(angle));
	step.x = dir_factor.x * (TILE_SIZE / (tan(angle)));
	step.y = dir_factor.y * (TILE_SIZE);
	//printf("horiz func / before while loop\n");
	while (is_in_map(data, intersection_pt) && !is_wall(data, intersection_pt))
	{
		printf("horiz func / in while loop\n");
		intersection_pt.x += step.x;
		intersection_pt.y += step.y;
	}
	distance = fdim(intersection_pt.y, data->player_pos.y) / (sin(angle));
	printf("horizontal intersection point is x : %f y: %f\n", intersection_pt.x, intersection_pt.y);
	//printf("horizontal distance : %f\n", distance);
    return distance;
}
void	raycast(t_data *data, float ray_angle, t_ray	*ray)
{
 	float   vert_distance;   
    float   horiz_distance;
	t_ipos	dir_factor;
	int 	direction;

	//printf("distance to wall func\n");
	direction = direction(ray_angle);
	if (direction == 0)
	{
		dir_factor.x = 1;
		dir_factor.y = 1;
	}
	else if (direction == 1)
	{
		dir_factor.x = -1;
		dir_factor.y = 1;
	}
	else if (direction == 2)
	{
		dir_factor.x = -1;
		dir_factor.y = -1;
	}
	if (direction == 3)
	{
		dir_factor.x = 1;
		dir_factor.y = -1;
	}
    vert_distance = vert_intersection(data, ray_angle, dir_factor);
    horiz_distance = horiz_intersection(data, ray_angle, dir_factor);
    if (vert_distance <= horiz_distance)
	{
       ray->distance = vert_distance;
	   ray->orientation = 0;
	}
    else
	{
        ray->distance = horiz_distance;
		ray->orientation = 1;
	}
}

void	render(t_data	*data)
{
	int i;
	int	nb_of_rays;
	float ray_angle;
	float	ray_angle_incr;//de cbien s'incr le ray_angle entre chaq ray
	t_ray	*ray;
	//float	*ray_length;

	/*
	t_fpos	intersection_point;
	t_fpos	point;
	int	opposite;

	opposite = data->win_size.x / 2;
	*/

	nb_of_rays =  data->win_size.x / PIX_BTW_RAYS;
	//ray_length = ft_calloc(nb_of_rays, sizeof (float));
	//ray = malloc(sizeof(t_ray));
	ray_angle = data->player_dir - (FOV /2);//1st, left most ray//normalize_angle
	ray_angle_incr = FOV / nb_of_rays;
	i = 0;
	printf("raycasting function / nb of rays : %d\n", nb_of_rays);
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
		raycast(data, ray_angle, ray);
		//printf("distance to wall is : %f\n", ray_length[i]);
	//render strip
		render_strip(data, ray_angle, ray);
	//add angle_increment => ray moves to the right
		ray_angle += ray_angle_incr;//check angle conformity
		i++;
	}
	//free(ray);
	//return (ray_length);
}