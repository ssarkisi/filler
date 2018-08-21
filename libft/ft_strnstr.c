/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 12:37:34 by ssarkisi          #+#    #+#             */
/*   Updated: 2017/11/04 12:37:34 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (*little == '\0')
		return ((char *)big);
	i = ft_strlen(little);
	while (*big != '\0' && len-- >= i)
	{
		if (*big == *little && ft_memcmp(big, little, i) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
