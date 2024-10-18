/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:38:17 by tchalaou          #+#    #+#             */
/*   Updated: 2024/10/18 18:07:17 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if(!data->mlx_ptr)
		perror_exit("could not load mlx", data);
	mlx_get_screen_size(data->mlx_ptr, &data->win_size.x, &data->win_size.y);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_size.x, data->win_size.y, "cub3D");
	if (!data->win_ptr)
		perror_exit("could not create window", data);
}
