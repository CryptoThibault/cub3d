/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:01:19 by tchalaou          #+#    #+#             */
/*   Updated: 2024/11/18 17:25:58 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	select_texture(t_fpos player_pos, t_inter inter)
{
	if (inter.orient && inter.pos.y <= player_pos.y)
		return (0);
	else if (inter.orient && inter.pos.y > player_pos.y)
		return (1);
	else if (!inter.orient && inter.pos.x <= player_pos.x)
		return (2);
	else if (!inter.orient && inter.pos.x > player_pos.x)
		return (3);
	else
		return (-1);
}
