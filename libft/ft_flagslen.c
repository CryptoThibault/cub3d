/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagslen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:26:54 by tchalaou          #+#    #+#             */
/*   Updated: 2023/12/12 16:24:26 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_flagslen(char c, char n, void (*value))
{
	if (c == '#' && *(int *)&value && ft_strchr("oxX", n))
		return (!(n == 'o') + 1);
	if (c == ' ' && *(int *)&value >= 0 && ft_strchr("di1", n))
		return (1);
	if (c == '+' && *(int *)&value >= 0 && ft_strchr("di", n))
		return (1);
	return (0);
}
