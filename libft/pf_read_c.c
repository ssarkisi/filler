/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_read_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 12:46:05 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/01/29 12:46:06 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		print_cl(va_list *args, t_format *format)
{
	wint_t		wc;
	char		*str;

	wc = va_arg(*args, wint_t);
	if (MB_CUR_MAX == 4)
	{
		str = ft_unicode(wc);
		ft_counter(ft_strlen(str));
	}
	else
	{
		str = ft_strnew(1);
		str[0] = (char)wc;
		ft_counter(1);
	}
	if (format->zero == -1)
		format->zero = -1;
	if ((char)wc == '\0' && MB_CUR_MAX == 4)
	{
		ft_counter(1);
		ft_putnstr(str, ft_strlen(str) + 1);
	}
	else
		ft_putstr(str);
	free(str);
}

static	void	print_c_(va_list *args, t_format *format)
{
	int		c;
	char	*str;
	int		f;
	int		i;

	c = va_arg(*args, int);
	f = 1;
	i = -1;
	if (c == '\0')
		f = 0;
	if ((c != '\0' && format->minus != -1) || c == '\0')
		format->width--;
	str = ft_strnew(1);
	str[0] = c;
	str = pf_set_precision_str(str, format->precision);
	str = pf_set_wight(str, format);
	while (++i > -1)
		if (f == 1 && str[i] == '\0')
			break ;
		else if (f == 0 && str[i] == '\0')
			f++;
	ft_counter(i);
	ft_putnstr(str, i);
	free(str);
}

void			pf_read_c(va_list *args, t_format *format)
{
	if (format->length == 'l')
		print_cl(args, format);
	else
		print_c_(args, format);
}
