/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_field.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:06:04 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/02/19 17:06:05 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		set_xy(t_filler *f, char *line, int i)
{
	if (i == 8)
	{
		f->fy = ft_atoin(line, i);
		while (line[i] >= '0' && line[i] <= '9')
			i++;
		f->fx = ft_atoin(line, i);
		f->field = malloc(sizeof(char *) * (f->fy + 1));
		f->field[f->fy] = NULL;
	}
	else if (i == 6)
	{
		f->py = ft_atoin(line, i);
		while (line[i] >= '0' && line[i] <= '9')
			i++;
		f->px = ft_atoin(line, i);
		f->piece = malloc(sizeof(char *) * (f->py + 1));
		f->piece[f->py] = NULL;
	}
	free(line);
}

void		set_stpos(t_filler *f)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (f->stpos[0] == 0 && f->stpos[1] == 0)
		while (f->fy > i)
		{
			while (f->fx > j)
			{
				if (f->field[i][j] == f->ch)
				{
					f->stpos[0] = i;
					f->stpos[1] = j;
				}
				if (f->field[i][j] == f->ch1)
				{
					f->stpos1[0] = i;
					f->stpos1[1] = j;
				}
				j++;
			}
			j = 0;
			i++;
		}
}

void		set_mynum(t_filler *f, char *line)
{
	int		num;

	num = 0;
	if (ft_strstr(line, "ssarkisi") != NULL)
	{
		if (ft_strstr(line, "$$$ exec p1") != NULL)
			num = 1;
		else if (ft_strstr(line, "$$$ exec p2") != NULL)
			num = 2;
		f->mynum = num;
	}
	if (f->mynum == 1)
	{
		f->ch = 'O';
		f->ch1 = 'X';
	}
	else if (f->mynum == 2)
	{
		f->ch = 'X';
		f->ch1 = 'O';
	}
	else
		f->ch = '\0';
}

char		*cut_line(char *l)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (l[i] != ' ')
		i++;
	ret = malloc(sizeof(char) * (ft_strlen(l) - i));
	while (l[++i] != '\0')
	{
		ret[j] = l[i];
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

void		set_field(t_filler *f, int fd)
{
	char	*line;
	int		i;

	i = 0;
	get_next_line(fd, &line);
	free(line);
	while (i < f->fy && get_next_line(fd, &line) > 0)
	{
		f->field[i] = cut_line(line);
		i++;
		free(line);
	}
}
