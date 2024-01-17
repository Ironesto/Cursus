/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:38:30 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/09/16 19:41:03 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*res;

	i = 0;
	res = (const char *)s;
	while (i < n)
	{
		if (res[i] == (char)c)
			return ((void *)&res[i]);
		i++;
	}
	return (NULL);
}
