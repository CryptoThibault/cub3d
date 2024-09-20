
#include "cub3d.h"

int	is_wall(t_data *data, t_fpos	pos)
{
	int	x;
	int	y;

	x = floor(pos.x);
	y = floor(pos.y);
	if (data->map[y][x] == '1')
		return (1);
	else
		return (0);
}
float	normalize_angle(float angle)
{
	float	normed_angle;

	normed_angle = angle;
	if (angle < 0)
		normed_angle += 2;
	if (angle >= 2)
		normed_angle -= 2;
	return (normed_angle);
}