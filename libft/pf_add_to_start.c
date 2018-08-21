/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_add_to_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 19:27:32 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/01/28 19:27:33 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*pf_add_to_start(char *str, char c, int num)
{
	char	*ret;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = ft_strlen(str);
	if (num > 0)
		size = size + num;
	ret = ft_strnew(size);
	while (i < num)
	{
		ret[i] = c;
		i++;
	}
	while (i < size)
	{
		ret[i] = str[j];
		i++;
		j++;
	}
	ret[i] = '\0';
	return (ret);
}
