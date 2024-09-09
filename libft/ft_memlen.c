/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:23:17 by tchalaou          #+#    #+#             */
/*   Updated: 2023/12/12 16:21:15 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memlen(char c, void *value)
{
	if (c == 'c')
		return (1);
	if (c == 's' && value)
		return (ft_strlen((char *)value));
	if (c == 's' && !value)
		return (6);
	if (c == 'p' && value)
		return (ft_lnbr_baselen(*(long *)&value, 16) + 2);
	if (c == 'p' && !value)
		return (5);
	if (c == 'd' || c == 'i')
		return (ft_nbrlen(*(int *)&value));
	if (c == 'u')
		return (ft_unbrlen(*(unsigned int *)&value));
	if (c == 'x' || c == 'X')
		return (ft_nbr_baselen(*(int *)&value, 16));
	if (c == 'o')
		return (ft_nbr_baselen(*(int *)&value, 8));
	if (c == '%')
		return (1);
	return (0);
}
