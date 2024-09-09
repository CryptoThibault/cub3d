/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:36:28 by tchalaou          #+#    #+#             */
/*   Updated: 2023/12/12 16:19:12 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_printf_mem(const char **format, void *value, int *len)
{
	if (ft_strchr("# +", **format))
	{
		ft_putflags_fd(**format, *(*format + 1), value, 1);
		*len += ft_flagslen(**format, *(*format + 1), value);
		(*format)++;
		if (**format == '1')
			(*format)++;
	}
	ft_putmem_fd(**format, value, 1);
	*len += ft_memlen(**format, value);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	void	*value;
	int		len;

	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format == '%' && ft_strchr("cspdiuxX%# +", *(format + 1)))
		{
			format++;
			if (*format != '%')
				value = va_arg(args, void *);
			ft_printf_mem(&format, value, &len);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			len++;
		}
		format++;
	}
	return (len);
}
