/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_baselen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:44:57 by tchalaou          #+#    #+#             */
/*   Updated: 2023/12/12 16:23:12 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbr_baselen(unsigned int nbr, int base_len)
{
	int	len;

	len = 0;
	if (!nbr)
		len++;
	while (nbr > 0)
	{
		len++;
		nbr /= base_len;
	}
	return (len);
}
