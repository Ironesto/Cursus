/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:49:56 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/09/30 18:33:54 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (-1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	ft_putpointer(unsigned long i, char *base)
{
	unsigned long	n;
	int				res;

	n = i;
	res = 0;
	if (n >= 16)
		res += ft_putpointer(n / 16, base);
	if (res == 0)
	{
		write(1, "0x", 2);
		res += 2;
	}
	write(1, &base[n % 16], 1);
	res++;
	return (res);
}
