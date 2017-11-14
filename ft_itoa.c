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

char				*ft_itoa(int n)
{
	int				neg;
	int				digit;
	int				i;
	unsigned int	num;
	char			*str;

	if ((str = ft_strnew(11)) == NULL)
		return (NULL);
	neg = n < 0 ? -1 : 1;
	num = neg * n;
	i = 10;
	if (num == 0)
		return (ft_strcpy(str, "0"));
	while (num > 0 && i > 0)
	{
		digit = num % 10;
		str[i] = '0' + digit;
		i--;
		num /= 10;
	}
	if (neg == -1)
		str[i--] = '-';
	return (str + i + 1);
}
