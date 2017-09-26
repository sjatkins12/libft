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

static void	ft_itoa_helper(int n, char *ret)
{
	char	digit[2];

	digit[0] = (n % 10) + '0';
	digit[1] = '\0';
	if (n >= 10)
	{
		ft_itoa_helper(n / 10, ret);
	}
	ft_strcat(ret, digit);
}

static int	ft_count_digits(int n)
{
	int		digits;

	digits = 1;
	while (n >= 10)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

static char	*ft_check_min(int n)
{
	char	*ret;

	if (n == -2147483647 - 1)
	{
		ret = (char *)malloc(sizeof(char) * (12));
		ft_strcpy(ret, "-2147483648");
		return (ret);
	}
	return (NULL);
}

char		*ft_itoa(int n)
{
	char	*ret;
	int		negative;

	negative = 0;
	if (n == 0)
	{
		ret = (char *)malloc(sizeof(char) * 2);
		ret = "0";
		return (ret);
	}
	if (n < 0)
	{
		negative = 1;
		n *= -1;
		if ((ret = ft_check_min(n)))
			return (ret);
	}
	ret = (char *)malloc(sizeof(char) * (ft_count_digits(n) + negative + 1));
	if (!ret)
		return (NULL);
	if (negative == 1)
		ft_strcat(ret, "-");
	ft_itoa_helper(n, ret);
	ret[ft_count_digits(n) + negative] = '\0';
	return (ret);
}
