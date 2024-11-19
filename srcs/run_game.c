/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:13:52 by tchalaou          #+#    #+#             */
/*   Updated: 2024/11/19 17:53:48 by achevron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	run_game(t_data	*data)
{
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask,
		&handle_keyrelease, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask,
		&close_window, data);
	mlx_loop_hook(data->mlx_ptr, handle_key, data);
	render(data);
	mlx_loop(data->mlx_ptr);
}
