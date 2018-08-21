/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_add_to_end_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 19:28:09 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/01/28 19:28:10 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*pf_add_to_end_char(char *str, char c, int num)
{
	char	*ret;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = ft_strlen("1");
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
