/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:21:48 by ssarkisi          #+#    #+#             */
/*   Updated: 2017/11/11 13:21:49 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_toarray(char **tmp, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c)
		{
			start = i;
			while (s[i] != '\0' && s[i] != c)
				i++;
			tmp[j] = ft_strsub(s, start, i - start);
			j++;
			tmp[j] = NULL;
		}
	}
	tmp[j] = 0;
	return (tmp);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tmp;

	if (s == NULL ||
		(tmp = (char**)malloc(sizeof(char*) * (ft_arrsize(s, c) + 1))) == NULL)
		return (NULL);
	ft_bzero(tmp, (ft_arrsize(s, c) + 1));
	return (ft_toarray(tmp, s, c));
}
