/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:34:17 by tchalaou          #+#    #+#             */
/*   Updated: 2023/12/12 16:19:27 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putmem_fd(char c, void *value, int fd)
{
	if (c == 'c')
		ft_putchar_fd(*(char *)&value, fd);
	if (c == 's' && value)
		ft_putstr_fd((char *)value, fd);
	if (c == 's' && !value)
		ft_putstr_fd("(null)", 1);
	if (c == 'p' && value)
	{
		ft_putstr_fd("0x", 1);
		ft_putlnbr_base_fd(*(long *)&value, "0123456789abcdef", fd);
	}
	if (c == 'p' && !value)
		ft_putstr_fd("(nil)", 1);
	if (c == 'd' || c == 'i')
		ft_putnbr_fd(*(int *)&value, fd);
	if (c == 'u')
		ft_putunbr_fd(*(unsigned int *)&value, fd);
	if (c == 'x')
		ft_putnbr_base_fd(*(int *)&value, "0123456789abcdef", fd);
	if (c == 'X')
		ft_putnbr_base_fd(*(int *)&value, "0123456789ABCDEF", fd);
	if (c == 'o')
		ft_putnbr_base_fd(*(int *)&value, "01234567", fd);
	if (c == '%')
		ft_putchar_fd('%', fd);
}
