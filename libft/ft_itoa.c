/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:08:47 by tchalaou          #+#    #+#             */
/*   Updated: 2023/12/12 16:36:46 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_convert_int(char *p, long n)
{
	*p = 0;
	while (n > 0)
	{
		*--p = n % 10 + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	long	nb;
	int		l;
	char	*r;
	char	*p;

	nb = n;
	l = ft_nbrlen(nb);
	r = malloc(l + 1);
	if (!r)
		return (NULL);
	p = r;
	if (!nb)
	{
		*p++ = '0';
		*p = 0;
		return (r);
	}
	if (nb < 0)
	{
		*p = '-';
		nb = -nb;
	}
	p += l;
	ft_convert_int(p, nb);
	return (r);
}
