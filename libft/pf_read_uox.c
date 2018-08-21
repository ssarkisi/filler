/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_read_uox.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 12:50:28 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/01/29 12:50:28 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_pow(char c)
{
	int			pow;

	pow = 0;
	if (c == 'u')
		pow = 10;
	if (c == 'o')
		pow = 8;
	if (c == 'x' || c == 'X')
		pow = 16;
	return (pow);
}

static char		*uox_tostr(uintmax_t n, t_format *format)
{
	char		*nb;

	if (format->length == 'H')
		nb = ft_itoa_base((unsigned char)n, get_pow(format->type));
	else if (format->length == 'h')
		nb = ft_itoa_base((unsigned short int)n, get_pow(format->type));
	else if (format->length == 'l')
		nb = ft_itoa_base((unsigned long int)n, get_pow(format->type));
	else if (format->length == 'L')
		nb = ft_itoa_base((unsigned long long int)n, get_pow(format->type));
	else if (format->length == 'j')
		nb = ft_itoa_base(n, get_pow(format->type));
	else if (format->length == 'z')
		nb = ft_itoa_base((size_t)n, get_pow(format->type));
	else
		nb = ft_itoa_base((unsigned int)n, get_pow(format->type));
	return (nb);
}

static char		*convert_uox(uintmax_t n, char *nb, t_format *format)
{
	if (format->precision == 0 && n == 0)
		nb[0] = '\0';
	if (format->precision == -1 && format->zero == -1)
		if (format->hash != -1 && format->type == 'o' && nb[0] != '0')
			nb = pf_add_to_start(nb, '0', 1);
	if (format->precision == -1 && format->zero == -1)
		if (format->hash != -1 && (format->type == 'x' ||
			format->type == 'X') && n > 0)
			nb = pf_add_0x(nb, ft_strlen(nb));
	if ((format->hash != -1 && format->width != -1 && format->precision != -1)
		|| (format->zero != -1 && format->hash != -1))
	{
		if ((format->type == 'x' || format->type == 'X') &&
			(format->width -= 2))
			nb = pf_set_wight(nb, format);
		if ((format->type == 'o') && (format->width -= 1))
			nb = pf_set_wight(nb, format);
	}
	if (format->precision != -1 || format->zero != -1)
		if (format->hash != -1 && format->type == 'o' && nb[0] != '0')
			nb = pf_add_to_start(nb, '0', 1);
	if ((format->precision != -1 || format->zero != -1) && (format->hash != -1
		&& (format->type == 'x' || format->type == 'X') && n > 0))
		nb = pf_add_0x(nb, ft_strlen(nb));
	return (nb);
}

void			pf_read_uox(va_list *args, t_format *format)
{
	uintmax_t	n;
	char		*nb;

	n = va_arg(*args, intmax_t);
	nb = uox_tostr(n, format);
	nb = pf_set_precision_num(nb, format->precision);
	nb = convert_uox(n, nb, format);
	nb = pf_set_wight(nb, format);
	ft_counter(ft_strlen(nb));
	if (format->type == 'X')
		ft_putstr_in_upper(nb);
	else
		ft_putnstr(nb, ft_strlen(nb));
	free(nb);
}
