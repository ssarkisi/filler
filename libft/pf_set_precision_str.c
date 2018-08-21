/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_set_precision_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 12:31:05 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/01/29 12:31:06 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*pf_set_precision_str(char *s, int precision)
{
	int		len;
	char	*ret;

	len = ft_strlen(s);
	if (precision > len || precision == -1)
		return (s);
	else
	{
		ret = ft_strnew(precision);
		ret = ft_strncpy(ret, s, precision);
		free(s);
		return (ret);
	}
	free(s);
}
