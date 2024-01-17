/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:16:27 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/10/02 18:49:01 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_percent(char const *str, va_list args, int i)
{
	if (str[i + 1] == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (str[i + 1] == 's')
		return (ft_putstr(va_arg(args, char *)) - 2);
	if (str[i + 1] == 'p')
		return (ft_putpointer(va_arg(args, unsigned long), "0123456789abcdef")
			- 2);
	if (str[i + 1] == 'd' || str[i + 1] == 'i')
		return (ft_putnbr(va_arg(args, int), "0123456789") - 2);
	if (str[i + 1] == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int), "0123456789") - 2);
	if (str[i + 1] == 'x')
		return (ft_putnbr_hexa(va_arg(args, unsigned int), "0123456789abcdef")
			- 2);
	if (str[i + 1] == 'X')
		return (ft_putnbr_hexa(va_arg(args, unsigned int), "0123456789ABCDEF")
			- 2);
	if (str[i + 1] == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		t;
	va_list	args;

	va_start(args, str);
	i = 0;
	t = 0;
	while (str[i])
	{
		while (str[i] == '%' && str[i + 1] != '\0')
		{
			t += ft_percent(str, args, i);
			i += 2;
		}
		if (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	va_end(args);
	return (t + i);
}
