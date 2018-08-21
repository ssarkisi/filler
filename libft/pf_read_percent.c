/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_read_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:47:20 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/01/29 14:47:21 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pf_read_percent(t_format *format, char c)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew(1);
	str[0] = c;
	if (format->precision == 0)
		format->precision = 1;
	str = pf_set_precision_str(str, format->precision);
	str = pf_set_wight(str, format);
	ft_counter(ft_strlen(str));
	ft_putnstr(str, ft_strlen(str));
	free(str);
}
