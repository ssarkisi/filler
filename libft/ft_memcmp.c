/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 09:53:19 by ssarkisi          #+#    #+#             */
/*   Updated: 2017/11/04 09:53:25 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*arr1;
	const unsigned char	*arr2;

	if (s1 == s2 || n == 0)
		return (0);
	arr1 = (const unsigned char *)s1;
	arr2 = (const unsigned char *)s2;
	while (0 < n--)
	{
		if (*arr1 == *arr2)
		{
			arr1++;
			arr2++;
		}
		else
		{
			return (*arr1 - *arr2);
		}
	}
	return (0);
}
