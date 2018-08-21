/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:48:45 by ssarkisi          #+#    #+#             */
/*   Updated: 2017/11/11 15:48:46 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_arrsize(char const *s, char c)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = 0;
	while (i < ft_strlen(s))
	{
		if (i == 0 && s[i] != c)
			size++;
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			size++;
		i++;
	}
	return (size);
}
