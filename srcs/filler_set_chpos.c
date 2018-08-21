/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_set_chpos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:22:30 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/02/19 16:22:31 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			find_left(t_filler *f, char c)
{
	int		i;
	int		j;
	int		ret;

	i = 0;
	j = 0;
	ret = 0;
	while (f->fx > j)
	{
		while (f->fy > i)
		{
			if (f->field[i][j] == c)
				return (j);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int			find_right(t_filler *f, char c)
{
	int		i;
	int		j;
	int		ret;

	i = 0;
	j = f->fx - 1;
	ret = 0;
	while (j >= 0)
	{
		while (f->fy > i)
		{
			if (f->field[i][j] == c)
				return (j);
			i++;
		}
		i = 0;
		j--;
	}
	return (0);
}

int			find_top(t_filler *f, char c)
{
	int		i;
	int		ret;
	char	s[2];

	s[0] = c;
	s[1] = '\0';
	i = 0;
	while (f->fy > i)
	{
		if (ft_strstr(f->field[i], s) != NULL)
			return (i);
		i++;
	}
	ret = 0;
	return (0);
}

int			find_down(t_filler *f, char c)
{
	int		i;
	int		ret;
	char	s[2];

	s[0] = c;
	s[1] = '\0';
	i = f->fy - 1;
	while (i >= 0)
	{
		if (ft_strstr(f->field[i], s) != NULL)
			return (i);
		i--;
	}
	ret = 0;
	return (0);
}

void		set_chpos(t_filler *f)
{
	f->chpos[0] = find_left(f, f->ch);
	f->chpos[1] = find_right(f, f->ch);
	f->chpos[2] = find_top(f, f->ch);
	f->chpos[3] = find_down(f, f->ch);
	f->ch1pos[0] = find_left(f, f->ch1);
	f->ch1pos[1] = find_right(f, f->ch1);
	f->ch1pos[2] = find_top(f, f->ch1);
	f->ch1pos[3] = find_down(f, f->ch1);
}
