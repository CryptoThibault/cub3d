/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:55:02 by tchalaou          #+#    #+#             */
/*   Updated: 2024/09/27 15:21:24 by achevron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	array_size(char **array)
{
	int	size;

	size = 0;
	while (array[size])
		size++;
	return (size);
}

void	get_map(t_data *data, char **array, t_ipos pos)
{
	data->map = malloc(sizeof(char *) * ((array_size(array + pos.y) + 1)));
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
}

int	get_line_count(int fd)
{
	char	*line;
	int		count;

	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		count++;
	}
	return (count);
}

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
	char	**numbers;
	int		i;

	pos->x++;
	ignore_whitespace(array, pos);
	i = pos->x - 1;
	while (array[pos->y][++i])
		if (!ft_isdigit(array[pos->y][i]) && array[pos->y][i] != ',')
			perror_exit("color format not valid", data);
	numbers = ft_split(array[pos->y] + pos->x, ',');
	if (array_size(numbers) != 3)
		perror_exit("color format not valid", data);
	i = -1;
	while (++i < 3)
	{
		rgb[i] = ft_atoi(numbers[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			perror_exit("color format not valid", data);
	}
	free_array(numbers);
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
			perror_exit("invalid prefix on element line" , data);
		count++;
	}
	if (count < 6)
		perror_exit("not all element line have been read", data);
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
		array[i][ft_strlen(array[i]) - 1] = 0;
	}
	array[i] = NULL;
	close(fd);
	return (array);
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
	while (data->array[pos.y] && ignore_whitespace(data->array, &pos))
		pos.y++;
	get_map(data, data->array, pos);
	init_keylist(data);
	return (data);
}
