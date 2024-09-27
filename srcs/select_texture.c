/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:01:19 by tchalaou          #+#    #+#             */
/*   Updated: 2024/09/27 17:34:19 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	select_texture(float dir, int ori)
{
	if ((dir >= 1 && dir < 1.5 && ori) || (dir >= 1.5 && dir < 2 && ori))
		return (0);
	else if ((dir >= 0 && dir < 0.5 && ori) || (dir >= 0.5 && dir < 1 && ori))
		return (1);
	else if ((dir >= 0.5 && dir < 1 && !ori) || (dir >= 1 && dir < 1.5 && !ori))
		return (2);
	else if ((dir >= 0 && dir < 0.5 && !ori) || (dir >= 1.5 && dir < 2 && !ori))
		return (3);
}
