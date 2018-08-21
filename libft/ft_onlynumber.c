/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_onlynumber.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:46:57 by ssarkisi          #+#    #+#             */
/*   Updated: 2017/11/11 15:46:58 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_onlynumber(char *str)
{
	char	*tmp;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_numbercount(str);
	if ((tmp = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			tmp[j] = str[i];
			j++;
		}
		i++;
	}
	return (tmp);
}
