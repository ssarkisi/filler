/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_place.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:45:52 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/02/19 16:45:53 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		best_place(t_filler *f, int i, int i1)
{
	int		min_y;
	int		min_x;
	int		res;

	min_y = ft_mod(f->goal[0] - f->place[1][i]);
	min_x = ft_mod(f->goal[1] - f->place[2][i]);
	res = min_y + min_x;
	while (f->place[0][0] > i && f->place[1][i] != -999 &&
		f->place[2][i] != -999)
	{
		min_y = ft_mod(f->goal[0] - f->place[1][i]);
		min_x = ft_mod(f->goal[1] - f->place[2][i]);
		if (res > (min_y + min_x))
		{
			res = min_y + min_x;
			i1 = i;
		}
		i++;
	}
	if ((f->place[1][i1] - f->y_tost) < -100 ||
		(f->place[2][i1] - f->x_tost) < -100)
		write_xy(0, 0, 1);
	else
		write_xy(f->place[1][i1] - f->y_tost, f->place[2][i1] - f->x_tost, 1);
}

void		add_place(t_filler *f, int y, int x)
{
	int		i;

	i = 0;
	if (f->place[1][f->place[0][0] - 1] != -999 ||
		f->place[2][f->place[0][0] - 1] != -999)
		realloc_int_arr(f, 1);
	while (i < f->place[0][0])
	{
		if (f->place[1][i] == -999 && f->place[2][i] == -999)
		{
			f->place[1][i] = y;
			f->place[2][i] = x;
			return ;
		}
		i++;
	}
}

int			check_place(t_filler *f, int x, int y, int flag)
{
	int		i;
	int		j;
	int		x1;

	i = -1;
	x1 = x;
	while (f->sy > ++i)
	{
		j = -1;
		while (f->sx > ++j)
		{
			if ((f->field[y] == NULL || f->field[y][x] == '\0') ||
				((f->field[y][x] != '.' && f->field[y][x] != f->ch)
					&& f->shape[i][j] == '*') || (flag > 1))
				return (-3);
			if (f->field[y][x] == f->ch && f->shape[i][j] == '*')
				flag++;
			x++;
		}
		y++;
		x = x1;
	}
	if (flag == 1)
		return (1);
	return (0);
}

void		set_all_place(t_filler *f)
{
	int		i;
	int		j;
	int		ret;

	i = 0;
	j = 0;
	while (f->fy > i)
	{
		while (f->fx > j)
		{
			ret = check_place(f, j, i, 0);
			if (ret == 1)
			{
				add_place(f, i, j);
				ret = 0;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void		find_place(t_filler *f)
{
	set_all_place(f);
	best_place(f, 0, 0);
	free(f->place[0]);
	free(f->place[1]);
	free(f->place[2]);
	free(f->place);
	free_array(f->field, f->fy);
	free_array(f->piece, f->py);
	free_array(f->shape, f->sy);
}
