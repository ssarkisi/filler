/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_find_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 18:58:33 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/01/28 18:58:34 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	pf_find_type(char *s, int end)
{
	int		i;
	char	*type;

	i = 0;
	type = "sSpdDioOuUxXcC";
	while (type[i] != '\0')
	{
		if (type[i] == s[end])
			return (type[i]);
		i++;
	}
	return ('\0');
}
