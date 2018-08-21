/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_add_to_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 19:28:42 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/01/28 19:28:43 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*pf_add_to_end(char *str, char c, int num)
{
	char	*ret;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = ft_strlen(str);
	if (num > 0)
		size += num;
	ret = ft_strnew(size);
	while (i < (size - num))
	{
		ret[i] = str[j];
		i++;
		j++;
	}
	while (i < size)
	{
		ret[i] = c;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
