/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 22:58:39 by satkins           #+#    #+#             */
/*   Updated: 2016/07/19 23:00:46 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	ch1;
	unsigned char	ch2;

	ch1 = (unsigned char)*s1;
	ch2 = (unsigned char)*s2;
	i = 0;
	while (*s1 != '\0' && *s2 != '\0' && i < n)
	{
		ch1 = (unsigned char)*s1;
		ch2 = (unsigned char)*s2;
		if (ch1 != ch2)
			return (ch1 - ch2);
		s1++;
		s2++;
		i++;
	}
	if (i == n)
		return (0);
	return (ch1 - ch2);
}
