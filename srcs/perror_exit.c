/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:54:52 by tchalaou          #+#    #+#             */
/*   Updated: 2024/09/10 15:17:07 by achevron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    destroy_textures(t_data *data, int nb)
{
    int    i;

    i = -1;
    while (++i < nb)
        if (data->textures[i])
            mlx_destroy_image(data->mlx_ptr, data->textures[i]);
}

void	free_window(t_data *data)
{
	if(data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
} 

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
	if (data->textures)
		free_textures(data, 4);
	if (data->mlx_ptr)
		free_window(data);
	free(data);
}

void	perror_exit(char *msg, t_data *data)
{
	printf("Error: %s\n", msg);
	if (data)
		free_data(data);
	exit(EXIT_FAILURE);
}
