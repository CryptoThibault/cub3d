/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:55:10 by tchalaou          #+#    #+#             */
/*   Updated: 2024/09/10 19:45:01 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_array(char **array)
{
	int	i = -1;
	while (array[++i])
	{
		printf("%s\n", array[i]);
	}
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		perror_exit("Usage: ./cub3D <infile>", NULL);
	data = create_data(av[1]);
	print_array(data->map);
	check_map(data);
	printf("Check done!\n");
	//create_window(data);
	//load_textures(data);
	//run_game(data);
	free_data(data);
	return (EXIT_SUCCESS);
}
