/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:26:37 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/02/19 16:26:38 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		write_xy(int y, int x, int fd)
{
	ft_putnbr_fd(y, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(x, fd);
	ft_putchar_fd('\n', fd);
}

void		set_xy_tost(t_filler *f)
{
	int		i;
	int		j;
	int		y;

	i = 0;
	j = 0;
	y = -1;
	f->x_tost = get_cut_start(f->piece);
	while (f->piece[i] != NULL)
	{
		while (f->piece[i][j] != '\0')
		{
			if (y == -1 && ft_strstr(f->piece[i], "*") != NULL)
			{
				f->y_tost = i;
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void		set_goal(t_filler *f)
{
	if (f->chpos[2] <= f->ch1pos[2] && f->chpos[0] <=
		f->ch1pos[0] && f->stpos[0] < f->stpos1[0])
		left_top_position_aloritm(f);
	else
		right_down_position_aloritm(f);
}

void		filler(t_filler *f, int flag, int fd)
{
	if (flag == 0)
	{
		set_field(f, fd);
		if (f->stflag == 0 && (f->stflag = 1))
			set_stpos(f);
	}
	else if (flag == 1)
	{
		set_piece(f, fd);
		cut_shape(f);
		set_xy_tost(f);
		set_chpos(f);
		set_goal(f);
		realloc_int_arr(f, 0);
		find_place(f);
	}
}

int			main(void)
{
	char		*line;
	t_filler	*f;

	f = get_new_struct();
	while (get_next_line(0, &line) > 0)
		if (ft_strstr(line, "$$$") != NULL)
		{
			set_mynum(f, line);
			free(line);
		}
		else if (ft_strstr(line, "Plateau") != NULL)
		{
			set_xy(f, line, 8);
			filler(f, 0, 0);
		}
		else if (ft_strstr(line, "Piece") != NULL)
		{
			set_xy(f, line, 6);
			filler(f, 1, 0);
		}
		else
			free(line);
	free(f);
	return (0);
}
