/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:26:11 by tchalaou          #+#    #+#             */
/*   Updated: 2024/11/18 15:25:54 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_textures(t_data *data)
{
	data->textures[0] = mlx_xpm_file_to_image(data->mlx_ptr, data->north_texture,
			&data->tex_size[0].x, &data->tex_size[0].y);
	if (!data->textures[0])
		perror_exit("failed to load north texture", data);
	data->textures[1] = mlx_xpm_file_to_image(data->mlx_ptr, data->south_texture,
			&data->tex_size[1].x, &data->tex_size[1].y);
	if (!data->textures[1])
		perror_exit("failed to load south texture", data);
	data->textures[2] = mlx_xpm_file_to_image(data->mlx_ptr, data->west_texture,
			&data->tex_size[2].x, &data->tex_size[2].y);
	if (!data->textures[2])
		perror_exit("failed to load west texture", data);
	data->textures[3] = mlx_xpm_file_to_image(data->mlx_ptr, data->east_texture,
			&data->tex_size[3].x, &data->tex_size[3].y);
	if (!data->textures[3])
		perror_exit("failed to load east exture", data);
}
