/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:54:52 by tchalaou          #+#    #+#             */
/*   Updated: 2024/09/10 14:33:00 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

void	free_data(t_data *data)
{
	if (data->map)
		free_array(data->map);
	free(data);
}

void	perror_exit(char *msg, t_data *data)
{
	printf("Error: %s\n", msg);
	if (data)
		free_data(data);
	exit(EXIT_FAILURE);
}
