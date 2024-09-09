/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:35:17 by tchalaou          #+#    #+#             */
/*   Updated: 2023/12/12 16:27:15 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_next_buffer(char **bu, char **ln)
{
	char	*nl;
	char	*new;
	char	*tmp;

	nl = ft_strchr(*bu, '\n');
	new = NULL;
	if (nl && *(nl + 1))
	{
		new = ft_strdup(nl + 1);
		*(nl + 1) = 0;
	}
	if (!*ln)
		*ln = ft_strdup(*bu);
	else
	{
		tmp = ft_strjoin(*ln, *bu);
		free(*ln);
		*ln = tmp;
	}
	free(*bu);
	*bu = new;
	return (!!nl);
}

static void	read_next_line(int fd, char **bu, char **ln)
{
	ssize_t	br;

	while (1)
	{
		*bu = malloc(BUFFER_SIZE + 1);
		if (!*bu)
			break ;
		br = read(fd, *bu, BUFFER_SIZE);
		if (br < 1)
		{
			free(*bu);
			*bu = NULL;
			break ;
		}
		*(*bu + br) = 0;
		if (get_next_buffer(bu, ln))
			break ;
		if (br != BUFFER_SIZE)
			break ;
	}
}

char	*get_next_line(int fd)
{
	static char	*bu[1024];
	char		*ln;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE < 1)
		return (NULL);
	ln = NULL;
	if (bu[fd] && get_next_buffer(&bu[fd], &ln))
		return (ln);
	bu[fd] = NULL;
	read_next_line(fd, &bu[fd], &ln);
	return (ln);
}
