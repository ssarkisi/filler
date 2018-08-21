/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_algoritm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:25:20 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/02/19 16:25:21 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		left_top_position_aloritm(t_filler *f)
{
	f->goal[0] = f->ch1pos[2] - 2;
	f->goal[1] = f->ch1pos[1] + 2;
	if ((check_top(f, f->ch) != -1 || check_right(f, f->ch) != -1) &&
		check_down(f, f->ch) != -1)
	{
		f->goal[0] = f->fy;
		f->goal[1] = f->fx;
	}
	else if ((check_top(f, f->ch) != -1 || check_right(f, f->ch) != -1) &&
		(check_down(f, f->ch) == -1 || check_left(f, f->ch) == -1))
	{
		f->goal[0] = f->ch1pos[3] - 2;
		f->goal[1] = f->ch1pos[0] - 2;
	}
	else if (
		(check_top(f, f->ch) != -1 || check_right(f, f->ch) != -1) &&
		(check_down(f, f->ch) == -1 && check_left(f, f->ch) == -1) &&
		check_right(f, f->ch1) != -1)
	{
		f->goal[0] = f->ch1pos[3];
		f->goal[1] = 0;
	}
}

void		right_down_position_aloritm(t_filler *f)
{
	f->goal[0] = f->ch1pos[3] + 2;
	f->goal[1] = f->ch1pos[0] - 2;
	if ((check_down(f, f->ch) != -1 || check_left(f, f->ch) != -1) &&
		check_top(f, f->ch) != -1)
	{
		f->goal[0] = 0;
		f->goal[1] = 0;
	}
	else if ((check_down(f, f->ch) != -1 || check_left(f, f->ch) != -1) &&
		(check_top(f, f->ch) == -1 || check_right(f, f->ch) == -1))
	{
		f->goal[0] = f->ch1pos[2] - 2;
		f->goal[1] = f->ch1pos[1] + 2;
	}
	else if (
		(check_down(f, f->ch) != -1 || check_left(f, f->ch) != -1) &&
		(check_top(f, f->ch) == -1 && check_right(f, f->ch) == -1) &&
		check_left(f, f->ch1) != -1)
	{
		f->goal[0] = f->ch1pos[2];
		f->goal[1] = f->fx;
	}
}
