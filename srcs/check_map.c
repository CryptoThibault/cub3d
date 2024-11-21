/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:41:17 by tchalaou          #+#    #+#             */
/*   Updated: 2024/11/19 17:58:27 by achevron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player(t_data *data, t_ipos pos, char symbol)
{
	free(data->char_list);
	data->char_list = ft_strdup(" 01");
	data->player_pos.x = pos.x + 0.5;
	data->player_pos.y = pos.y + 0.5;
	if (symbol == 'N')
		data->player_dir = 1.5;
	else if (symbol == 'S')
		data->player_dir = 0.5;
	else if (symbol == 'E')
		data->player_dir = 0;
	else if (symbol == 'W')
		data->player_dir = 1;
}

void	check_outlines(t_data *data, t_ipos pos)
{
	if (pos.y == 0 || pos.y == data->map_size.y - 1)
		perror_exit("map symbol invalid", data);
	if (pos.x == 0 || pos.x == data->map_size.x - 1)
		perror_exit("map symbol invalid", data);
	if (!ft_strchr("01NSEW", data->map[pos.y - 1][pos.x]))
		perror_exit("map symbol invalid", data);
	if (!ft_strchr("01NSEW", data->map[pos.y + 1][pos.x]))
		perror_exit("map symbol invalid", data);
	if (!ft_strchr("01NSEW", data->map[pos.y][pos.x - 1]))
		perror_exit("map symbol invalid", data);
	if (!ft_strchr("01NSEW", data->map[pos.y][pos.x + 1]))
		perror_exit("map symbol invalid", data);
}

void	check_map(t_data *data)
{
	t_ipos	pos;

	data->char_list = ft_strdup(" 01NSEW");
	pos.y = -1;
	while (data->map[++pos.y])
	{
		pos.x = -1;
		while (data->map[pos.y][++pos.x])
		{
			if (!ft_strchr(data->char_list, data->map[pos.y][pos.x]))
				perror_exit("map symbol invalid", data);
			if (ft_strchr("NSEW", data->map[pos.y][pos.x]))
				set_player(data, pos, data->map[pos.y][pos.x]);
			else if (data->map[pos.y][pos.x] != '0')
				continue ;
			check_outlines(data, pos);
		}
	}
	if (!ft_strncmp(data->char_list, " 01NSEW", 7))
		perror_exit("player symbol not in the map", data);
	free(data->char_list);
	data->char_list = NULL;
}
