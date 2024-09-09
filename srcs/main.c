/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:55:10 by tchalaou          #+#    #+#             */
/*   Updated: 2024/09/09 16:58:08 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		return (printf("Usage: %s <infile>", av[0]), 1);
	data = create_data(av[1]);
	printf("ok");
	return (EXIT_SUCCESS);
}
