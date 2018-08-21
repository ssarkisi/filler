/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_find_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 18:52:33 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/01/28 18:52:34 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		pf_find_width(char *s, int start, int end)
{
	start++;
	while (s[start] == '#' || s[start] == '0' || s[start] == '-' ||
		s[start] == '+' || s[start] == ' ')
		start++;
	while (start < end)
	{
		if (s[start] == '.')
		{
			start++;
			while (s[start] >= '0' && s[start] <= '9')
				start++;
		}
		if (s[start] >= '0' && s[start] <= '9')
			return (ft_atoin(s, start));
		start++;
	}
	return (-1);
}
