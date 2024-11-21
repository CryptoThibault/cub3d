/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:55:02 by tchalaou          #+#    #+#             */
/*   Updated: 2024/11/19 18:52:28 by achevron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ignore_whitespace(char **array, t_ipos *pos)
{
	if (!ft_strlen(array[pos->y]))
		return (1);
	while (array[pos->y][pos->x])
	{
		if (!ft_strchr(" \t\v\r\f", array[pos->y][pos->x]))
			return (0);
		pos->x++;
	}
	return (1);
}

void	add_spaces(t_data *data)
{
	t_ipos	pos;
	int		size;
	char	*buffer;
	char	*temp;

	pos.y = -1;
	while (data->map[++pos.y])
	{
		size = data->map_size.x - ft_strlen(data->map[pos.y]);
		buffer = malloc(size + 1);
		if (!buffer)
			perror_exit("buffer allocation failed", data);
		pos.x = -1;
		while (++pos.x < size)
			buffer[pos.x] = ' ';
		buffer[size] = 0;
		temp = ft_strjoin(data->map[pos.y], buffer);
		free(data->map[pos.y]);
		free(buffer);
		data->map[pos.y] = temp;
	}
}

void	get_map(t_data *data, char **array, t_ipos pos)
{
	data->map = malloc(sizeof(char *) * (array_size(array + pos.y) + 1));
	if (!data->map)
		perror_exit("map allocation failed", data);
	data->map_size.y = -1;
	data->map_size.x = -1;
	while (array[pos.y])
	{
		data->map[++data->map_size.y] = ft_strdup(array[pos.y++]);
		pos.x = ft_strlen(data->map[data->map_size.y]);
		if (pos.x > data->map_size.x)
			data->map_size.x = pos.x;
	}
	data->map[++data->map_size.y] = NULL;
	if (data->map_size.x < 3 || data->map_size.y < 3)
		perror_exit("map not valid", data);
	add_spaces(data);
}

char	**read_infile(t_data *data, char *infile)
{
	char	**array;
	int		fd;
	int		lc;
	int		i;

	fd = open(infile, O_RDONLY);
	if (fd == -1)
		perror_exit("can't open infile", data);
	lc = get_line_count(fd);
	close(fd);
	fd = open(infile, O_RDONLY);
	if (fd == -1)
		perror_exit("can't open infile", data);
	array = malloc(sizeof(char *) * (lc + 1));
	if (!array)
		perror_exit("array allocation failed", data);
	i = -1;
	while (++i < lc)
	{
		array[i] = get_next_line(fd);
		if (array[i][ft_strlen(array[i]) - 1] == '\n')
			array[i][ft_strlen(array[i]) - 1] = 0;
	}
	array[i] = NULL;
	return (close(fd), array);
}

t_data	*create_data(char *infile)
{
	t_data	*data;
	t_ipos	pos;

	if (ft_strncmp(infile + ft_strlen(infile) - 4, ".cub", 4))
		perror_exit("infile don't end with .cub", NULL);
	data = ft_calloc(sizeof(t_data), 1);
	if (!data)
		perror_exit("data allocation failed", NULL);
	data->array = read_infile(data, infile);
	data->floor_rgb[0] = -1;
	data->ceiling_rgb[0] = -1;
	get_elements(data, data->array, &pos);
	pos.x = 0;
	while (data->array[pos.y] && ignore_whitespace(data->array, &pos))
		pos.y++;
	get_map(data, data->array, pos);
	init_keylist(data);
	return (data);
}
