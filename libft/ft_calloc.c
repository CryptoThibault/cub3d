/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:34:31 by tchalaou          #+#    #+#             */
/*   Updated: 2023/11/15 15:12:45 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*mem;

	if (size != 0 && nmemb >= SIZE_MAX / size)
		return (NULL);
	total_size = nmemb * size;
	mem = malloc(total_size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, total_size);
	return (mem);
}
