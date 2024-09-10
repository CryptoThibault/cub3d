/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:18:18 by achevron          #+#    #+#             */
/*   Updated: 2024/09/10 15:32:49 by achevron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    load_textures(t_data *data)
{
    data->textures[0] = mlx_xpm_file_to_image(data->mlx_ptr, data->north_texture,
            &data->width, &data->height);
    if (!data->textures[0])
        perror_exit("failed to load texture",data);
    data->textures[1] = mlx_xpm_file_to_image(data->mlx_ptr, data->south_texture,
            &data->width, &data->height);
    if (!data->textures[1])
        perror_exit("failed to load texture",data);
    data->textures[2] = mlx_xpm_file_to_image(data->mlx_ptr, data->west_texture,
            &data->width, &data->height);
    if (!data->textures[2])
        perror_exit("failed to load texture",data);
    data->textures[3] = mlx_xpm_file_to_image(data->mlx_ptr, data->east_texture,
            &data->width, &data->height);
    if (!data->textures[3])
        perror_exit("failed to load texture",data);
}