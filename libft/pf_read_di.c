/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_read_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 12:49:56 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/01/29 12:49:57 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*check_sign(char *nb)
{
	int		i;

	i = 1;
	if (nb[0] == '0' || nb[0] == '+')
	{
		while (nb[i] != '\0')
		{
			if (nb[i] == '-' || nb[i] == '+')
			{
				nb[0] = nb[i];
				nb[i] = '0';
			}
			i++;
		}
	}
	return (nb);
}

static char	*di_tostr(intmax_t n, t_format *format)
{
	char		*nb;
	char		*tmp;

	if (format->length == 'H')
		nb = ft_itoa((signed char)n);
	else if (format->length == 'h')
		nb = ft_itoa((short int)n);
	else if (format->length == 'l')
		nb = ft_itoa((long int)n);
	else if (format->length == 'L')
		nb = ft_itoa((long long int)n);
	else if (format->length == 'j')
		nb = ft_itoa(n);
	else if (format->length == 'z')
		nb = ft_itoa((size_t)n);
	else
		nb = ft_itoa((int)n);
	tmp = ft_strdup(nb);
	ft_memdel((void **)&nb);
	nb = pf_set_precision_num(tmp, format->precision);
	return (nb);
}

static char	*pf_read_di_helper(char *nb, t_format *format)
{
	char		*tmp;

	if ((format->plus != -1 && nb[0] != '-' && format->precision != -1) ||
		(format->plus != -1 && format->width == -1 && format->precision == -1
			&& nb[0] != '-') || (format->plus != -1 && format->zero != -1 &&
			format->width < (int)ft_strlen(nb)))
	{
		tmp = ft_strdup(nb);
		ft_memdel((void **)&nb);
		nb = pf_add_to_start(tmp, '+', 1);
		ft_memdel((void **)&tmp);
	}
	else if (format->plus != -1 && format->precision == -1 && nb[0] != '-')
		nb[0] = '+';
	else if (format->plus == -1 && nb[0] != '-' && format->space != -1 &&
		nb[0] != ' ')
	{
		tmp = ft_strdup(nb);
		ft_memdel((void **)&nb);
		nb = pf_add_to_start(tmp, ' ', 1);
		ft_memdel((void **)&tmp);
	}
	return (nb);
}

void		pf_read_di(va_list *args, t_format *format)
{
	intmax_t	n;
	char		*nb;

	n = va_arg(*args, intmax_t);
	nb = di_tostr(n, format);
	if (format->space != -1 && format->width > 0 && format->zero != -1)
		format->width--;
	if (format->precision == 0 && n == 0)
		nb[0] = '\0';
	if (format->precision == -1)
		nb = pf_set_wight(nb, format);
	nb = pf_read_di_helper(nb, format);
	nb = pf_set_wight(nb, format);
	nb = check_sign(nb);
	ft_counter(ft_strlen(nb));
	ft_putnstr(nb, ft_strlen(nb));
	free(nb);
}
