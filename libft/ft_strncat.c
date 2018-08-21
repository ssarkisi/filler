/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:21:31 by ssarkisi          #+#    #+#             */
/*   Updated: 2017/11/04 11:21:32 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	char	*restrict tmp;

	tmp = s1;
	while (*tmp != '\0')
	{
		tmp++;
	}
	while (*s2 != '\0' && n > 0)
	{
		*tmp = *s2;
		tmp++;
		s2++;
		n--;
	}
	*tmp = '\0';
	return (s1);
}
