/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:41:17 by tchalaou          #+#    #+#             */
/*   Updated: 2024/09/10 19:40:25 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player(t_data *data, t_ipos pos, char symbol, char **char_list)
{
	free(*char_list);
	*char_list = ft_strdup(" 01");
	data->player_pos.x = pos.x + 0.5;
	data->player_pos.y = pos.y + 0.5;
	if (symbol == 'N')
		data->player_dir = 0;
	else if (symbol == 'S')
		data->player_dir = 180;
	else if (symbol == 'E')
		data->player_dir = 90;
	else if (symbol == 'W')
		data->player_dir = 270;
}

void	check_outlines(t_data *data, t_ipos pos)
{
	if  (pos.y == 0 || pos.y == data->map_size.y)
		perror_exit("the map is not surronded by '1'", data);
	if  (pos.x == 0 || pos.x == data->map_size.x)
		perror_exit("the map is not surronded by '1'", data);
	if (!ft_strchr("01NSEW", data->map[pos.y - 1][pos.x]))
		perror_exit("the map is not surronded by '1'", data);
	if (!ft_strchr("01NSEW", data->map[pos.y + 1][pos.x]))
		perror_exit("the map is not surronded by '1'", data);
	if (!ft_strchr("01NSEW", data->map[pos.y][pos.x - 1]))
		perror_exit("the map is not surronded by '1'", data);
	if (!ft_strchr("01NSEW", data->map[pos.y][pos.x + 1]))
		perror_exit("the map is not surronded by '1'", data);
}

void	check_map(t_data *data)
{
	t_ipos	pos;
	char	*char_list;

	char_list = ft_strdup(" 01NSEW");
	pos.y = -1;
	while (data->map[++pos.y])
	{
		pos.x = -1;	
		while (data->map[pos.y][++pos.x])
		{
			if (!ft_strchr(char_list, data->map[pos.y][pos.x]))
				perror_exit("invalid symbol in map", data);
			if (ft_strchr("NSEW", data->map[pos.y][pos.x]))
				set_player(data, pos, data->map[pos.y][pos.x], &char_list);
			else if (data->map[pos.y][pos.x] != '0')
				continue ;
			check_outlines(data, pos);
		}
	}
	if (!ft_strncmp(char_list, " 01NSEW", 7))
		perror_exit("the player symbol are not in the map", data);
	free(char_list);
}
