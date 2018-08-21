/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 11:51:51 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/01/18 11:51:52 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	mask2(char *str, wchar_t wch)
{
	unsigned char	mask1;
	unsigned char	mask2;

	mask1 = 192;
	mask2 = 128;
	str[0] = (wch >> 6) | mask1;
	str[1] = (wch & 63) | mask2;
	str[2] = '\0';
	str[3] = '\0';
	str[4] = '\0';
}

void	mask3(char *str, wchar_t wch)
{
	unsigned char	mask1;
	unsigned char	mask2;

	mask1 = 224;
	mask2 = 128;
	str[0] = (wch >> 12) | mask1;
	str[1] = ((wch >> 6) & 63) | mask2;
	str[2] = (wch & 63) | mask2;
	str[3] = '\0';
	str[4] = '\0';
}

void	mask4(char *str, wchar_t wch)
{
	unsigned char	mask1;
	unsigned char	mask2;

	mask1 = 240;
	mask2 = 128;
	str[0] = (wch >> 18) | mask1;
	str[1] = ((wch >> 12) & 63) | mask2;
	str[2] = ((wch >> 6) & 63) | mask2;
	str[3] = (wch & 63) | mask2;
	str[4] = '\0';
}

char	*ft_unicode(wchar_t wch)
{
	int		i;
	char	*str;

	str = malloc(sizeof(char) * 5);
	i = ft_sizeof_unicode(wch);
	if (i <= 7)
	{
		ft_bzero(str, 5);
		str[0] = wch;
	}
	else if (i <= 11)
		mask2(str, wch);
	else if (i <= 16)
		mask3(str, wch);
	else if (i > 16)
		mask4(str, wch);
	return (str);
}
