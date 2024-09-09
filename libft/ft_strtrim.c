/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:08:27 by tchalaou          #+#    #+#             */
/*   Updated: 2023/12/12 15:11:23 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	char	*p;
	int		i;
	int		e;

	i = 0;
	e = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i]))
		i++;
	while (ft_strchr(set, s1[e]))
		e--;
	if (i > e)
		return (ft_strdup(""));
	s = malloc(e - i + 2);
	if (!s)
		return (NULL);
	p = s;
	while (i <= e)
		*p++ = s1[i++];
	*p = 0;
	return (s);
}
