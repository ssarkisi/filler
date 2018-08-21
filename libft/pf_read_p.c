/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_read_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 12:43:57 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/01/29 12:43:58 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*convert_zero_nb(char *nb, t_format *format, int i)
{
	if (i == 1)
	{
		nb[0] = '\0';
		nb = pf_add_0x(nb, 0);
		nb = pf_add_to_end(nb, '0', format->precision);
	}
	if (i == 2)
	{
		format->width -= 2;
		nb = pf_set_wight(nb, format);
		nb = pf_add_0x(nb, ft_strlen(nb));
	}
	if (i == 3)
	{
		nb = pf_add_to_start(nb, '0', format->precision - ft_strlen(nb));
		nb = pf_add_0x(nb, ft_strlen(nb));
	}
	if (i == 4)
	{
		nb = pf_add_0x(nb, ft_strlen(nb));
		nb = pf_set_wight(nb, format);
	}
	return (nb);
}

void		pf_read_p(va_list *args, t_format *format)
{
	void	*n;
	char	*nb;

	n = va_arg(*args, void *);
	nb = ft_itoa_base((uintmax_t)n, 16);
	if (nb[0] == '0' && format->precision == 0 &&
		format->width == -1 && format->zero == -1)
	{
		nb[0] = '\0';
		nb = pf_add_0x(nb, 0);
	}
	else if (nb[0] == '0' && format->precision > 0 && format->width == -1)
		nb = convert_zero_nb(nb, format, 1);
	else if (format->zero != -1 && format->precision == -1)
		nb = convert_zero_nb(nb, format, 2);
	else if (format->precision > (int)ft_strlen(nb) &&
		format->precision > format->width)
		nb = convert_zero_nb(nb, format, 3);
	else
		nb = convert_zero_nb(nb, format, 4);
	ft_counter(ft_strlen(nb));
	ft_putnstr(nb, ft_strlen(nb));
	free(nb);
}
