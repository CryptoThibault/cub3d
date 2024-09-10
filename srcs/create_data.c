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

void	get_texture(int fd, t_data *data, char *texture, char *prefix)
{
	char	*line;

	line = get_next_line(fd);
	if (ft_strncmp(line, prefix, 2))
		perror_exit("wrong texture line format", data);
	texture = ft_strdup(line);
	free(line);
}

void	get_rgb(int fd, t_data *data, int rgb[3], char *prefix)
{
	char	*line;
	int	i;

	line = get_next_line(fd);
	if (line[0] != prefix[0])
		perror_exit("wrong rgb line format", data);
	i = 3;
	rgb[0] = ft_atoi(&line[i]);
	while (line[++i] != ',')
		;
	rgb[1] = ft_atoi(&line[i]);
	while (line[++i] != ',')
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
		pos.x = ft_strlen(data->map[(int)pos.y]);
		if (pos.x > data->size.x)
			data->size.x = pos.x;
	}
	data->map[(int)pos.y] = NULL;
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
	data = malloc(sizeof(t_data));
	if (!data)
		perror_exit("data allocation failed", NULL);
	get_texture(fd, data, data->north_texture, "NO");
	get_texture(fd, data, data->south_texture, "SO");
	get_texture(fd, data, data->west_texture, "WE");
	get_texture(fd, data, data->east_texture, "EA");
	check_new_line(fd, data);
	get_rgb(fd, data, data->floor_rgb, "F");
	get_rgb(fd, data, data->ceiling_rgb, "C");
	check_new_line(fd, data);
	create_map(fd, data);
	close(fd);
	return (data);
}

//Compter le nombre de lignes du fichier
//Allouer et remplir un buffer avec get_next_line
//Detecter le prefix, ignorer les whitespaces et ecrire dans data
//Si une ligne est vide, on l'ignore
//Une fois la map detecter, on rempli data-map avec tout le contenu (on n'ignore plus les lignes vides)
