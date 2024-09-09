/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr_base_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:01:13 by tchalaou          #+#    #+#             */
/*   Updated: 2023/12/12 16:20:26 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlnbr_base_fd(unsigned long nbr, char *base, int fd)
{
	unsigned long	base_len;

	base_len = ft_strlen(base);
	if (nbr >= base_len)
		ft_putlnbr_base_fd(nbr / base_len, base, fd);
	ft_putchar_fd(base[nbr % base_len], fd);
}
