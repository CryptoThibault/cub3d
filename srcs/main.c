/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:55:10 by tchalaou          #+#    #+#             */
/*   Updated: 2024/11/24 14:25:32 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		perror_exit("Usage: ./cub3D <infile>", NULL);
	data = create_data(av[1]);
	check_map(data);
	create_window(data);
	load_textures(data);
	run_game(data);
	free_data(data);
	return (EXIT_SUCCESS);
}
