/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putflags_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:25:48 by tchalaou          #+#    #+#             */
/*   Updated: 2023/12/12 16:20:56 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putflags_fd(char c, char n, void *value, int fd)
{
	if (c == '#' && *(int *)&value && ft_strchr("xXo", n))
	{
		ft_putchar_fd('0', fd);
		if (n == 'x')
			ft_putchar_fd('x', fd);
		if (n == 'X')
			ft_putchar_fd('X', fd);
	}
	if (c == ' ' && *(int *)&value >= 0 && ft_strchr("di1", n))
		ft_putchar_fd(' ', fd);
	if (c == '+' && *(int *)&value >= 0 && ft_strchr("di", n))
		ft_putchar_fd('+', fd);
}
