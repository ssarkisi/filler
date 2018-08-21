/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_set_precision_num.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 12:30:40 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/01/29 12:30:42 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*pf_set_precision_num(char *s, int precision)
{
	int		len;
	char	*ret;
	int		sign;

	sign = 0;
	if (s[0] == '-')
		sign = -1;
	len = ft_strlen(s);
	if (sign == -1)
		precision++;
	if (precision > len)
	{
		if (sign == -1 && (s[0] = '0'))
			precision--;
		if (sign != -1)
			ret = pf_add_to_start(s, '0', (precision - len));
		if (sign == -1)
			ret = pf_add_to_start(s, '0', (precision - len + 1));
		if (sign == -1)
			ret[0] = '-';
	}
	else
		ret = ft_strdup(s);
	free(s);
	return (ret);
}
