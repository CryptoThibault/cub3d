/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achevron <achevron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:01:19 by tchalaou          #+#    #+#             */
/*   Updated: 2024/11/18 12:35:53 by achevron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	select_texture(float dir, int ori)
{
	int	tex_id;

	tex_id = 0;
	if ((dir >= 1 && dir < 1.5 && ori) || (dir >= 1.5 && dir < 2 && ori))
		tex_id = 0;
	else if ((dir >= 0 && dir < 0.5 && ori) || (dir >= 0.5 && dir < 1 && ori))
		tex_id = 1;
	else if ((dir >= 0.5 && dir < 1 && !ori) || (dir >= 1 && dir < 1.5 && !ori))
		tex_id = 2;
	else if ((dir >= 0 && dir < 0.5 && !ori) || (dir >= 1.5 && dir < 2 && !ori))
		tex_id = 3;
	return (tex_id);
}