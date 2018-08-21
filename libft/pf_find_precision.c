/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_find_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 18:54:39 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/01/28 18:54:39 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pf_find_precision(char *s, int start, int end)
{
	while (start < end)
	{
		if (s[start] == '.')
			return (ft_atoin(s, start + 1));
		start++;
	}
	return (-1);
}
