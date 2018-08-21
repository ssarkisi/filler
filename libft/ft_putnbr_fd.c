/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:34:57 by ssarkisi          #+#    #+#             */
/*   Updated: 2017/11/08 16:34:58 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		arr[10];
	int		i;

	i = 0;
	if (n == 0)
		ft_putchar_fd('0', fd);
	if (n == -2147483648)
	{
		arr[0] = 8;
		n = n / 10;
		i++;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	while (n > 0)
	{
		arr[i++] = n % 10;
		n = n / 10;
	}
	while (--i >= 0)
		ft_putchar_fd(arr[i] + '0', fd);
}
