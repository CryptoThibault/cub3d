/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:12:06 by tchalaou          #+#    #+#             */
/*   Updated: 2023/12/12 15:18:27 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*r;
	size_t	rl;

	rl = ft_strlen(s);
	if (!s || start >= rl)
		return (ft_strdup(""));
	s += start;
	if (start + len > rl)
		len = rl - start;
	r = malloc(len + 1);
	if (!r)
		return (NULL);
	ft_strlcpy(r, s, len + 1);
	return (r);
}
