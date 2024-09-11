/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:55:02 by tchalaou          #+#    #+#             */
/*   Updated: 2024/09/11 19:40:27 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
void	get_texture(int fd, t_data *data, char **texture, char *prefix)
{
	char	*line;

	line = get_next_line(fd);
	if (ft_strncmp(line, prefix, 2))
		perror_exit("wrong texture line format", data);
	*texture = ft_strdup(line + 3);
	free(line);
}

void	get_rgb(int fd, t_data *data, int rgb[3], char *prefix)
{
	char	*line;
	int	i;

	line = get_next_line(fd);
	if (line[0] != prefix[0])
		perror_exit("wrong rgb line format", data);
	i = 2;
	rgb[0] = ft_atoi(&line[i]);
	while (line[++i - 1] != ',')
		;
	rgb[1] = ft_atoi(&line[i]);
	while (line[++i - 1] != ',')
		;
	rgb[2] = ft_atoi(&line[i]);
	free(line);
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

void	create_map(int fd, t_data *data)
{
	t_ipos	pos;

	data->map_size.y = 14;//get_line_count(fd);
	data->map = malloc(sizeof(char *) * (data->map_size.y + 1));
	if (!data->map)
		perror_exit("map allocaton failed", data);
	pos.y = -1;
	data->map_size.x = 0;
	while (++pos.y < data->map_size.y)
	{
		data->map[pos.y] = get_next_line(fd);
		pos.x = ft_strlen(data->map[pos.y]) - 1;
		data->map[pos.y][pos.x] = 0;
		if (pos.x > data->map_size.x)
			data->map_size.x = pos.x;
	}
	data->map[pos.y] = NULL;
}

void	check_new_line(int fd, t_data *data)
{
	char	*line;

	line = get_next_line(fd);
	if (ft_strncmp(line, "\n", 2))
		perror_exit("wrong infile format", data);
	free(line);
}

t_data	*create_data(char *infile)
{
	t_data	*data;
	int	fd;

	if (ft_strncmp(infile + ft_strlen(infile) - 4, ".cub", 4))
		perror_exit("infile don't end with .cub", NULL);
	fd = open(infile, O_RDONLY);
	if (fd == -1)
		perror_exit("can't open infile", NULL);
	data = ft_calloc(sizeof(t_data), 1);
	if (!data)
		perror_exit("data allocation failed", NULL);
	get_texture(fd, data, &data->north_texture, "NO");
	get_texture(fd, data, &data->south_texture, "SO");
	get_texture(fd, data, &data->west_texture, "WE");
	get_texture(fd, data, &data->east_texture, "EA");
	check_new_line(fd, data);
	get_rgb(fd, data, data->floor_rgb, "F");
	get_rgb(fd, data, data->ceiling_rgb, "C");
	check_new_line(fd, data);
	create_map(fd, data);
	close(fd);
	return (data);
}
*/
//-------------------------

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
	while (array[(*pos).y][(*pos).x])
	{
		if (!ft_strchr(" \t\v\r\f", array[(*pos).y][(*pos).x]))
			return (0);
		(*pos).x++;
	}
	return (1);
}

void	get_texture(t_data *data, char **texture, char **array, t_ipos *pos)
{
	(*pos).x += 2;
	ignore_whitespace(array, pos);
	*texture = ft_strdup(array[(*pos).y] + (*pos).x);
	(void)data;
}

void	get_rgb(t_data *data, int rgb[3], char **array, t_ipos *pos)
{
	char	**numbers;
	int		i;

	(*pos).x++;
	ignore_whitespace(array, pos);
	i = (*pos).x - 1;
	while (array[(*pos).y][++i])
		if (!ft_isdigit(array[(*pos).y][i]) && array[(*pos).y][i] != ',')
			perror_exit("color format not valid", data);
	numbers = ft_split(array[(*pos).y] + (*pos).x, ',');
	//if (arraylen(numbers) != 3)
	//	perror_exit("color format not valid", data);
	i = -1;
	while (++i < 3)
	{
		rgb[i] = ft_atoi(numbers[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			perror_exit("color format not valid", data);
		printf("rgb: %d\n", rgb[i]);
	}
	free_array(numbers);
}

void	get_elements(t_data *data, char **array, t_ipos *pos)
{
	int	count;

	count = 0;
	while (array[++(*pos).y] && count++ < 6)
	{
		(*pos).x = 0;
		if (ignore_whitespace(array, pos))
		{
			count--;
			continue ;
		}
		if (!data->north_texture && ft_strncmp(array[(*pos).y], "NO ", 3))
			get_texture(data, &data->north_texture, array, pos);
		else if (!data->south_texture && ft_strncmp(array[(*pos).y], "SO ", 3))
			get_texture(data, &data->south_texture, array, pos);
		else if (!data->east_texture && ft_strncmp(array[(*pos).y], "EA ", 3))
			get_texture(data, &data->east_texture, array, pos);
		else if (!data->west_texture && ft_strncmp(array[(*pos).y], "WE ", 3))
			get_texture(data, &data->west_texture, array, pos);
		else if (ft_strncmp(array[(*pos).y], "F ", 2))
			get_rgb(data, data->floor_rgb, array, pos);
		else if (ft_strncmp(array[(*pos).y], "C ", 2))
			get_rgb(data, data->ceiling_rgb, array, pos);
		else
			perror_exit("invalid prefix on element line" , data);
	}
}

char	**read_infile(char *infile)
{
	char	**array;
	int		fd;
	int		lc;
	int		i;

	fd = open(infile, O_RDONLY);
	if (fd == -1)
		perror_exit("can't open infile", NULL);
	lc = get_line_count(fd);
	close(fd);
	fd = open(infile, O_RDONLY);
	if (fd == -1)
		perror_exit("can't open infile", NULL);
	array = malloc(sizeof(char *) * (lc + 1));
	if (!array)
		perror_exit("array allocation failed", NULL);
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
	char	**array;
	t_ipos	pos;

	if (ft_strncmp(infile + ft_strlen(infile) - 4, ".cub", 4))
		perror_exit("infile don't end with .cub", NULL);
	array = read_infile(infile);
	data = ft_calloc(sizeof(t_data), 1);
	if (!data)
		perror_exit("data allocation failed", NULL);
	pos.y = -1;
	get_elements(data, array, &pos);
	while (ignore_whitespace(array, &pos))
		pos.y++;
	//get_map(data, array, pos);
	free_array(array);
	return (data);
}
