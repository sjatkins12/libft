/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 22:58:39 by satkins           #+#    #+#             */
/*   Updated: 2018/04/26 10:43:02 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_index(int nb, int *nbr, size_t *len)
{
	int		index;

	index = 0;
	if (nb > 0)
		while (nb > 0)
		{
			nbr[index] = (nb % 10);
			nb = nb / 10;
			index++;
		}
	else
	{
		ft_putchar('-');
		while (nb < 0)
		{
			nbr[index] = (nb % 10) * -1;
			nb = nb / 10;
			index++;
		}
		*len = 1;
	}
	*len += (size_t)index;
	while (--index >= 0)
		ft_putchar(nbr[index] + '0');
}

size_t		ft_putnbr(int n)
{
	size_t	len;
	int		nbr[10];

	len = 0;
	if (n == 0)
	{
		ft_putchar('0');
		len = 1;
	}
	else
		ft_print_index(n, nbr, &len);
	return (len);
}

static void	ft_printul_index(size_t nb, int *nbr, size_t *len)
{
	int		index;

	index = 0;
	while (nb > 0)
	{
		nbr[index] = (nb % 10);
		nb = nb / 10;
		index++;
	}
	*len += (size_t)index;
	while (--index >= 0)
		ft_putchar(nbr[index] + '0');
}

size_t		ft_putul(size_t n)
{
	size_t	len;
	int		nbr[20];

	len = 0;
	if (n == 0)
	{
		ft_putchar('0');
		len = 1;
	}
	else
		ft_printul_index(n, nbr, &len);
	return (len);
}
