/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:54:25 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/10/17 19:43:01 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int i, char *base)
{
	long	n;
	int		res;

	n = i;
	res = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		res++;
	}
	if (n >= 10)
		res += ft_putnbr(n / 10, base);
	write(1, &base[n % 10], 1);
	res++;
	return (res);
}

int	ft_putnbr_hexa(unsigned int i, char *base)
{
	unsigned long	n;
	int				res;

	n = i;
	res = 0;
	if (n >= 16)
		res += ft_putnbr_hexa(n / 16, base);
	write(1, &base[n % 16], 1);
	res++;
	return (res);
}

int	ft_putnbr_u(unsigned int nbr, char *base)
{
	long	n;
	int		res;

	n = nbr;
	res = 0;
	if (n >= 10)
		res += ft_putnbr(n / 10, base);
	write(1, &base[n % 10], 1);
	res++;
	return (res);
}
