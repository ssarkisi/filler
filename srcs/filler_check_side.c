/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_check_side.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:18:34 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/02/19 16:18:37 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			check_left(t_filler *f, char c)
{
	int		i;

	i = 0;
	while (i < f->fy)
	{
		if (f->field[i][0] == c)
			return (i);
		i++;
	}
	return (-1);
}

int			check_right(t_filler *f, char c)
{
	int		i;

	i = 0;
	while (i < f->fy)
	{
		if (f->field[i][f->fx - 1] == c)
			return (i);
		i++;
	}
	return (-1);
}

int			check_top(t_filler *f, char c)
{
	int		i;

	i = 0;
	while (i < f->fx)
	{
		if (f->field[0][i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int			check_down(t_filler *f, char c)
{
	int		i;

	i = 0;
	while (i < f->fx)
	{
		if (f->field[f->fy - 1][i] == c)
			return (i);
		i++;
	}
	return (-1);
}
