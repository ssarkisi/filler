/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_del_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 17:56:01 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/02/01 17:56:03 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		pf_del_struct(t_format *format)
{
	t_format	*tmp;

	if (format)
	{
		format = format->first;
		while (format->next != NULL)
		{
			tmp = format->next;
			free(format);
			format = tmp;
		}
		free(format);
	}
}
