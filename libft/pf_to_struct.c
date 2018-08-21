/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_to_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 19:13:03 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/01/28 19:13:05 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_format	*new_format(char *s, int start, int end)
{
	t_format	*new;

	new = malloc(sizeof(t_format));
	new->hash = pf_find_flags(s, start, '#');
	new->zero = pf_find_flags(s, start, '0');
	new->minus = pf_find_flags(s, start, '-');
	new->plus = pf_find_flags(s, start, '+');
	new->space = pf_find_flags(s, start, ' ');
	new->width = pf_find_width(s, start, end);
	new->precision = pf_find_precision(s, start, end);
	new->length = pf_find_length(s, start, end, 0);
	new->type = pf_next_type(s, start);
	new->next = NULL;
	return (new);
}

int					pf_to_struct(char *s, int start, int i, t_format **format)
{
	t_format	*new;
	t_format	*tmp;

	while (pf_is_type(s[i]) != 1 && s[i] != '\0')
		i++;
	tmp = *format;
	new = new_format(s, start, i);
	if (tmp == NULL)
	{
		new->first = new;
		tmp = new;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		new->first = tmp->first;
		tmp->next = new;
		tmp = tmp->first;
	}
	*format = tmp->first;
	return (i);
}
