/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 12:25:07 by ssarkisi          #+#    #+#             */
/*   Updated: 2017/11/04 12:25:16 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	srclen;

	i = 0;
	j = 0;
	srclen = ft_strlen(src);
	while (dst[i] != '\0' && i < size)
		i++;
	if (size > 0)
		while (src[j] != '\0' && i < size - 1)
			dst[i++] = src[j++];
	if (j > 0)
	{
		dst[i] = '\0';
		return (srclen + i - j);
	}
	return (srclen + i);
}
