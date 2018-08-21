/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:00:14 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/01/29 13:00:16 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_format	*parse(char *s)
{
	int			i;
	t_format	*format;

	i = 0;
	format = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] == '%')
			i += 2;
		if (s[i] == '%')
		{
			i = pf_to_struct(s, i, i, &format);
		}
		i++;
	}
	return (format);
}

static void		print_args(va_list *args, t_format *format)
{
	if (format->minus != -1)
		format->zero = -1;
	if (format->type == 'S' || format->type == 'D' || format->type == 'O' ||
		format->type == 'U' || format->type == 'C')
	{
		format->type = format->type + 32;
		format->length = 'l';
	}
	if (format->type == 'd' || format->type == 'i')
		pf_read_di(args, format);
	else if (format->type == 'u' || format->type == 'o' ||
		format->type == 'x' || format->type == 'X')
		pf_read_uox(args, format);
	else if (format->type == 'c')
		pf_read_c(args, format);
	else if (format->type == 's')
		pf_read_s(args, format);
	else if (format->type == 'p')
		pf_read_p(args, format);
	else
		pf_read_percent(format, format->type);
}

static int		print_param_percent(int i, char *s, va_list *args, t_format *f)
{
	int		n;

	n = ++i;
	while (pf_is_type(s[i]) != 1 && s[i] != '%' && s[i] != '\0')
		i++;
	if (pf_is_type(f->type) == 1 || f->type == '%')
		i++;
	if (pf_is_type(f->type) != 1)
		i = pf_next_type_pos(s, n) + 1;
	print_args(args, f);
	return (i);
}

static void		print_param(char *s, va_list *args, t_format *format, int i)
{
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] == '%')
		{
			ft_putchar(s[i]);
			ft_counter(1);
			i += 2;
			continue ;
		}
		if (s[i] == '%')
		{
			i = print_param_percent(i, s, args, format);
			format = format->next;
		}
		if ((int)ft_strlen(s) < i)
			i = (int)ft_strlen(s);
		if (s[i] != '%' && s[i] != '\0')
		{
			ft_putchar(s[i]);
			ft_counter(1);
			i++;
		}
	}
}

int				ft_printf(char *s, ...)
{
	va_list		args;
	t_format	*format;

	if (s[0] == '%' && s[1] == '\0')
		return (0);
	format = parse(s);
	va_start(args, s);
	print_param(s, &args, format, 0);
	va_end(args);
	pf_del_struct(format);
	return (ft_counter(-1));
}
