/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_find_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 18:51:01 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/01/28 18:51:02 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	pf_find_flags(char *s, int start, char c)
{
	start++;
	while (s[start] == '#' || s[start] == '0' || s[start] == '-' ||
		s[start] == '+' || s[start] == ' ')
	{
		if (s[start] == c)
			return (start);
		start++;
	}
	return (-1);
}
