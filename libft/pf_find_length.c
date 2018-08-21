/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_find_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 18:56:23 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/01/28 18:56:25 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	pf_find_length(char *s, int start, int end, int i)
{
	i = start;
	while (i++ < end)
		if (s[i] == 'z')
			return ('z');
	i = start;
	while (i++ < end)
		if (s[i] == 'j')
			return ('j');
	i = start;
	while (i++ < end)
		if (s[i] == 'l' && s[i + 1] == 'l')
			return ('L');
	i = start;
	while (i++ < end)
		if (s[i] == 'l')
			return ('l');
	i = start;
	while (i++ < end)
		if (s[i] == 'h' && (s[i + 1] != 'h' && s[i - 1] != 'h'))
			return ('h');
	i = start;
	while (i++ < end)
		if (s[i] == 'h' && s[i + 1] == 'h')
			return ('H');
	return ('\0');
}
