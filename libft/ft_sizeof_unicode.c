/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizeof_unicode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 21:03:11 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/01/31 21:03:13 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sizeof_unicode(wchar_t wch)
{
	int		i;

	i = 0;
	while (wch != 0)
	{
		wch = wch >> 1;
		i++;
	}
	return (i);
}
