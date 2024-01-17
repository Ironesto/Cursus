/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:42:42 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/09/14 19:34:56 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dest);
	j = 0;
	while (src[j] && i < n - 1 && n != 0)
		dest[i++] = src[j++];
	dest[i] = '\0';
	if (n > i - j)
		return (ft_strlen(src) + (i - j));
	else
		return (n + ft_strlen(src));
}
