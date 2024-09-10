/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:55:02 by tchalaou          #+#    #+#             */
/*   Updated: 2024/09/10 13:47:39 by achevron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_texture(char *line, char *prefix)
{
	char	*path;

	(void)prefix;
/*	if (ft_strncmp(line, ft_strcat(prefix, " ./"), 5));
	{
		printf("Error: texture path line wrong");
		exit(EXIT_FAILURE);
	}
*/

	path = ft_strdup(line + 3);
	free(line);
	return (path);
}

int	get_rgb(char *line, char *prefix)[3]
{
	int	rgb[3];
	int	i;

	(void)prefix;
/*	if (ft_strncmp(line, ft_strcat(prefix, " "), 2));
	{
		printf("Error: rgb line wrong");
		exit(EXIT_FAILURE);
	}	
*/
	i = 3;
	rgb[0] = ft_atoi(&line[i]);
	while (line[i - 1] == ',')
		i++;
	rgb[1] = ft_atoi(&line [i]);
	while (line[i - 1] == ',')
		i++;
	rgb[2] = ft_atoi(&line[i]);
	return (rgb);
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
	t_pos	pos;

	data->size.y = get_line_count(fd);
	data->map = malloc(sizeof(char *) * (data->size.y + 1));
	if (!data->map)
		perror_exit("map allocaton failed", data);
	pos.y = -1;
	data->size.x = 0;
	while (++pos.y < data->size.y)
	{
		data->map[(int)pos.y] = get_next_line(fd);
		pos.x  = ft_strlen(data->map[(int)pos.y]);
		if (pos.x > data->size.x)
			data->size.x = pos.x;
	}
	data->map[(int)pos.y] = NULL;
}

t_data	*create_data(char *infile)
{
	t_data	*data;
	int	fd;
	char	*new_line;

	if (!infile /*check .cub*/)
		perror_exit("infile should end with .cub", NULL);
	fd = open(infile, O_RDONLY);
	if (fd == -1)
		perror_exit("can't open infile", NULL);
	data = malloc(sizeof(t_data));
	if (!data)
		perror_exit("data allocation failed", NULL);
	data->north_texture = get_texture(get_next_line(fd), "NO");
	data->south_texture = get_texture(get_next_line(fd), "SO");
	data->west_texture = get_texture(get_next_line(fd), "WE");
	data->east_texture = get_texture(get_next_line(fd), "EA");
	new_line = get_next_line(fd);
	free(new_line);
	data->floor_rgb = get_rgb(get_next_line(fd), "F");
	data->ceiling_rgb = get_rgb(get_next_line(fd), "C");
	new_line = get_next_line(fd);
	free(new_line);
	create_map(fd, data);
	close(fd);
}
