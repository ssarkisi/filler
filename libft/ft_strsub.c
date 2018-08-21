/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:29:32 by ssarkisi          #+#    #+#             */
/*   Updated: 2017/11/08 11:29:33 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!s || (tmp = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (0 < len--)
	{
		tmp[i] = s[start++];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
