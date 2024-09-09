/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:22:48 by tchalaou          #+#    #+#             */
/*   Updated: 2023/11/14 19:14:45 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		while (*s && *s != c)
			s++;
		count++;
	}
	return (count);
}

static void	ft_fill_tab(char **tab, char const *s, char c)
{
	char	*p;

	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		p = (char *)s;
		while (*p && *p != c)
			p++;
		*tab = malloc(p - s + 1);
		if (!(*tab))
			break ;
		p = *tab;
		while (*s && *s != c)
			*p++ = *s++;
		*p = 0;
		tab++;
	}
	*tab = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	tab = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	ft_fill_tab(tab, s, c);
	return (tab);
}
