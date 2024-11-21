/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:54:52 by tchalaou          #+#    #+#             */
/*   Updated: 2024/11/19 18:01:10 by achevron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_textures(t_data *data, int nb)
{
	int	i;

	i = -1;
	while (++i < nb)
		if (data->textures[i])
			mlx_destroy_image(data->mlx_ptr, data->textures[i]);
}

void	free_window(t_data *data)
{
	if (data->win_ptr)
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
	if (data->array)
		free_array(data->array);
	free(data->north_texture);
	free(data->south_texture);
	free(data->east_texture);
	free(data->west_texture);
	if (data->num_array)
		free_array(data->num_array);
	if (data->char_list)
		free(data->char_list);
	if (data->map)
		free_array(data->map);
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
