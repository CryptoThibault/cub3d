/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:54:35 by tchalaou          #+#    #+#             */
/*   Updated: 2023/11/13 15:13:06 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = 0;
	if (size > 0)
	{
		while (*src && --size)
		{
			*dst++ = *src++;
			len++;
		}
		*dst = 0;
	}
	while (*src++)
		len++;
	return (len);
}
