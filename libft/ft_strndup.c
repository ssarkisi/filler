/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 19:02:52 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/02/07 19:02:54 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int n)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (s1[i] != '\0')
		i++;
	if ((str = (char*)malloc(sizeof(*str) * (i - n + 1))) == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		if (j >= n)
			str[j - n] = s1[j];
		j++;
	}
	str[j - n] = '\0';
	return (str);
}
