/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_add_0x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 19:27:11 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/01/28 19:27:12 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*pf_add_0x(char *str, int len)
{
	char	*ret;
	int		i;
	int		j;
	int		size;

	i = 2;
	j = 0;
	size = len + 2;
	ret = ft_strnew(size);
	ret[0] = '0';
	ret[1] = 'x';
	while (i < size)
	{
		ret[i] = str[j];
		i++;
		j++;
	}
	free(str);
	return (ret);
}
