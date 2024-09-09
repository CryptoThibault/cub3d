/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lnbr_baselen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:02:06 by tchalaou          #+#    #+#             */
/*   Updated: 2023/12/12 16:23:54 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lnbr_baselen(unsigned long nbr, int base_len)
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
