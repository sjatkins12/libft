/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ahtoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 16:28:33 by satkins           #+#    #+#             */
/*   Updated: 2018/05/19 18:25:26 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*pass_white_space(char *str)
{
	while (*str != '\0' && (*str == ' ' ||
		*str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	return (str);
}

static int	is_hexdigit(char c)
{
	c = ft_toupper(c);
	if ((c >= 'A' && c <= 'F') || (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

static char	*pass_prefix(char *str)
{
	if (*str == '0' && ft_toupper(*(str + 1)) == 'X')
		str += 2;
	return (str);
}

static int	hex_val(char c)
{
	static char	*digits = "0123456789ABCDEF";
	int			i;
	
	i = 0;
	c = ft_toupper(c);
	while (i < 16)
	{
		if (c == digits[i])
			return (i);
		i++;
	}
	return (-1);
}

int		ft_ahtoi(char *str)
{
	int	ret;

	ret = 0;
	str = pass_white_space(str);
	str = pass_prefix(str);
	if (is_hexdigit(*str) == 0)
		return (0);
	while (*str != '\0' && is_hexdigit(*str))
	{
		ret = (ret * 16) + hex_val(*str);
		str++;
	}
	return (ret);
}
