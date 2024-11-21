/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:26:36 by achevron          #+#    #+#             */
/*   Updated: 2024/11/19 18:52:11 by achevron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_texture(t_data *data, char *texture, char c)
{
	char	**tmp;

	tmp = ft_split(texture, c);
	if (array_size(tmp) != 1)
	{
		free_array(tmp);
		perror_exit("texture path format not valid", data);
	}
	free_array(tmp);
}

void	get_texture(t_data *data, char **texture, char **array, t_ipos *pos)
{
	pos->x += 2;
	ignore_whitespace(array, pos);
	*texture = ft_strdup(array[pos->y] + pos->x);
	check_texture(data, *texture, ' ');
	check_texture(data, *texture, '\t');
	check_texture(data, *texture, '\v');
	check_texture(data, *texture, '\r');
	check_texture(data, *texture, '\f');
}

void	get_rgb(t_data *data, int rgb[3], char **array, t_ipos *pos)
{
	int		i;

	pos->x++;
	ignore_whitespace(array, pos);
	i = pos->x - 1;
	while (array[pos->y][++i])
		if (!ft_isdigit(array[pos->y][i]) && array[pos->y][i] != ',')
			perror_exit("color format not valid", data);
	data->num_array = ft_split(array[pos->y] + pos->x, ',');
	if (array_size(data->num_array) != 3)
		perror_exit("color format not valid", data);
	i = -1;
	while (++i < 3)
	{
		rgb[i] = ft_atoi(data->num_array[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			perror_exit("color format not valid", data);
	}
	free_array(data->num_array);
	data->num_array = NULL;
}

void	select_elements(t_data *data, char **array, t_ipos *pos)
{
	if (!data->north_texture && !ft_strncmp(array[pos->y], "NO", 2))
		get_texture(data, &data->north_texture, array, pos);
	else if (!data->south_texture && !ft_strncmp(array[pos->y], "SO", 2))
		get_texture(data, &data->south_texture, array, pos);
	else if (!data->east_texture && !ft_strncmp(array[pos->y], "EA", 2))
		get_texture(data, &data->east_texture, array, pos);
	else if (!data->west_texture && !ft_strncmp(array[pos->y], "WE", 2))
		get_texture(data, &data->west_texture, array, pos);
	else if (data->floor_rgb[0] == -1 && !ft_strncmp(array[pos->y], "F", 1))
		get_rgb(data, data->floor_rgb, array, pos);
	else if (data->ceiling_rgb[0] == -1 && !ft_strncmp(array[pos->y], "C", 1))
		get_rgb(data, data->ceiling_rgb, array, pos);
	else
		perror_exit("invalid prefix on element line", data);
}

void	get_elements(t_data *data, char **array, t_ipos *pos)
{
	int	count;

	count = 0;
	pos->y = -1;
	while (array[++pos->y] && count < 6)
	{
		pos->x = 0;
		if (ignore_whitespace(array, pos))
			continue ;
		select_elements(data, array, pos);
		count++;
	}
	if (count < 6)
		perror_exit("not all element line have been read", data);
}
