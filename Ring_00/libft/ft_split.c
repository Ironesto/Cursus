/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:40:29 by gpaez-ga          #+#    #+#             */
/*   Updated: 2023/09/25 18:40:26 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == 0 || s[i + 1] == c))
			j++;
		i++;
	}
	return (j);
}

static char	*ft_save(char const *s, char c, size_t i)
{
	char	*res;
	size_t	j;

	j = i;
	while (s[j] != c && s[j])
		j++;
	res = malloc(sizeof(char) * (j - i + 1));
	if (!res)
		return (NULL);
	j = 0;
	while (s[i] && s[i] != c)
		res[j++] = s[i++];
	res[j] = '\0';
	return (res);
}

static char	**ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free (str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	j = 0;
	str = malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!str || s == NULL)
		return (NULL);
	while (s[j])
	{
		if (s[j] && s[j] != c)
		{
			str[i] = ft_save(s, c, j);
			if (str[i] == NULL)
				return (ft_free(str));
			i++;
			while (s[j + 1] && s[j + 1] != c)
				j++;
		}
		j++;
	}
	str[i] = NULL;
	return (str);
}
