/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:55:10 by tchalaou          #+#    #+#             */
/*   Updated: 2024/11/18 17:31:52 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*----------------------------*/
void	print_array(char **array)
{
	int	i = -1;
	while (array[++i])
		printf("%s\n", array[i]);
}

void	print_data(t_data *data)
{
	printf("NO %s\n", data->north_texture);
	printf("SO %s\n", data->south_texture);
	printf("WE %s\n", data->west_texture);
	printf("EA %s\n", data->east_texture);
	printf("F %d,%d,%d\n", data->floor_rgb[0], data->floor_rgb[1], data->floor_rgb[2]);
	printf("C %d,%d,%d\n\n", data->ceiling_rgb[0], data->ceiling_rgb[1], data->ceiling_rgb[2]);
	print_array(data->map);
	printf("\n[map size] x: %d, y: %d\n\n", data->map_size.x,  data->map_size.y);
}
/*---------------------------*/
int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		perror_exit("Usage: ./cub3D <infile>", NULL);
	data = create_data(av[1]);
	/*print_data(data); REMOVE*/
	check_map(data);
	create_window(data);
	load_textures(data);
	run_game(data);
	free_data(data);
	return (EXIT_SUCCESS);
}
