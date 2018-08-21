/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_set_wight.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 19:29:16 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/01/28 19:29:17 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*pf_set_wight(char *s, t_format *format)
{
	int		width2;
	char	*str;

	width2 = ft_strlen(s);
	if (format->minus == -1)
	{
		if ((format->zero == -1 || format->precision > -1) &&
		!((format->type == 'c' || format->type == 's' || format->type == '%'
		|| pf_is_type(format->type) == -1) && format->zero != -1))
			str = pf_add_to_start(s, ' ', (format->width - width2));
		else
			str = pf_add_to_start(s, '0', (format->width - width2));
	}
	else
	{
		if (format->type == 'c')
			str = pf_add_to_end_char(s, ' ', (format->width));
		else if (format->zero == -1 || format->precision > -1)
			str = pf_add_to_end(s, ' ', (format->width - width2));
		else
			str = pf_add_to_end(s, '0', (format->width - width2));
	}
	free(s);
	return (str);
}
