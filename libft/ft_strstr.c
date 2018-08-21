/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:33:58 by ssarkisi          #+#    #+#             */
/*   Updated: 2017/11/04 11:34:00 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *big, const char *little)
{
	char	*temp;
	int		x;
	int		i;

	if (*little == '\0')
		return ((char*)big);
	while (*big != '\0')
	{
		x = 0;
		i = 0;
		temp = (char*)big;
		while ((little[i] == big[x]) || (little[i] == '\0'))
		{
			if ((little[i] == '\0') || (big[x] == '\0'))
				return (temp);
			x++;
			i++;
		}
		big++;
	}
	return (0);
}
