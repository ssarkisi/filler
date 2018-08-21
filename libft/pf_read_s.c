/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_read_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 12:39:36 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/01/29 12:39:36 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		u_size(wchar_t *ws, int n, int i)
{
	int		j;
	int		f;
	int		ret;

	j = 0;
	f = 0;
	ret = 0;
	if (n < 1)
		return (n);
	while (ws != NULL && ws[j])
	{
		i = ft_sizeof_unicode(ws[j]);
		if (i <= 7)
			f = 1;
		else if (i <= 11)
			f = 2;
		else if (i <= 16)
			f = 3;
		else if (i > 16)
			f = 4;
		if ((ret + f) > n)
			return (ret);
		ret += f;
	}
	return (n);
}

static char		*convert_sl(wchar_t *ws, char *ret, int i)
{
	char		*str;
	char		*s;

	while (ws != NULL && ws[++i])
		if (MB_CUR_MAX == 4)
		{
			str = ft_unicode(ws[i]);
			s = ft_strdup(ret);
			ft_memdel((void **)&ret);
			ret = ft_strjoin(s, str);
			ft_memdel((void **)&s);
			free(str);
		}
		else
		{
			str = ft_strnew(1);
			str[0] = (char)ws[i];
			s = ft_strdup(ret);
			ft_memdel((void **)&ret);
			ret = ft_strjoin(s, str);
			ft_memdel((void **)&s);
			free(str);
		}
	return (ret);
}

static void		print_sl(va_list *args, t_format *format)
{
	wchar_t		*ws;
	char		*ret;

	ws = va_arg(*args, wchar_t *);
	if (ws == NULL)
		ret = ft_strdup("(null)");
	else
		ret = ft_strnew(0);
	ret = convert_sl(ws, ret, -1);
	format->precision = u_size(ws, format->precision, 0);
	ret = pf_set_precision_str(ret, format->precision);
	ret = pf_set_wight(ret, format);
	ft_counter(ft_strlen(ret));
	ft_putnstr(ret, ft_strlen(ret));
	free(ret);
}

static void		print_s_(va_list *args, t_format *format)
{
	char	*s;
	char	*str;

	s = va_arg(*args, char *);
	if (s == NULL)
		s = "(null)";
	str = ft_strnew(ft_strlen(s));
	str = ft_strcpy(str, s);
	str = pf_set_precision_str(str, format->precision);
	str = pf_set_wight(str, format);
	ft_counter(ft_strlen(str));
	ft_putnstr(str, ft_strlen(str));
	free(str);
}

void			pf_read_s(va_list *args, t_format *format)
{
	if (format->length == 'l')
		print_sl(args, format);
	else
		print_s_(args, format);
}
