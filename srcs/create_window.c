/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:38:17 by tchalaou          #+#    #+#             */
/*   Updated: 2024/11/21 15:38:23 by achevron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		perror_exit("could not load mlx", data);
	mlx_get_screen_size(data->mlx_ptr, &data->win_size.x, &data->win_size.y);
	data->win_size.x /= NUM_SCREEN;
	data->win_size.x *= WIN_RATIO;
	data->win_size.y *= WIN_RATIO;
	data->win_size.y -= BAR_SIZE;
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_size.x,
			data->win_size.y, "cub3D");
	if (!data->win_ptr)
		perror_exit("could not create window", data);
}
