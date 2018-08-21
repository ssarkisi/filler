/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_shape.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:57:25 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/02/19 16:57:26 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		set_piece(t_filler *f, int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (i < f->py)
	{
		get_next_line(fd, &line);
		f->piece[i] = line;
		i++;
	}
}

int			get_cut_start(char **ar)
{
	int		i;
	int		j;
	int		ret;

	i = 0;
	ret = -1;
	while (ar[i] != NULL)
	{
		j = 0;
		while (ar[i][j] != '\0')
		{
			if (ar[i][j] == '*')
			{
				if (ret == -1 || ret > j)
					ret = j;
				break ;
			}
			j++;
		}
		i++;
	}
	return (ret);
}

int			get_cut_end(char **ar)
{
	int		i;
	int		j;
	int		ret;

	i = 0;
	ret = -1;
	while (ar[i] != NULL)
	{
		j = 0;
		while (ar[i][j] != '\0')
		{
			if (ar[i][j] == '*')
			{
				if (ret == -1 || j > ret)
					ret = j;
			}
			j++;
		}
		i++;
	}
	return (ret);
}

char		*get_shape_line(char *s, int start, int end)
{
	int		i;
	char	*ret;

	i = 0;
	ret = malloc(sizeof(char) * (end - start + 2));
	while (start <= end)
	{
		ret[i] = s[start];
		i++;
		start++;
	}
	ret[i] = '\0';
	return (ret);
}

void		cut_shape(t_filler *f)
{
	int		i;
	int		n;
	int		start;
	int		end;

	i = -1;
	n = 0;
	while (f->piece[++i])
		if (ft_strstr(f->piece[i], "*"))
			n++;
	f->shape = malloc(sizeof(char *) * (n + 1));
	start = get_cut_start(f->piece);
	end = get_cut_end(f->piece);
	f->sx = end - start + 1;
	f->sy = n;
	i = -1;
	n = 0;
	while (f->piece[++i])
		if (ft_strstr(f->piece[i], "*"))
		{
			f->shape[n] = get_shape_line(f->piece[i], start, end);
			n++;
		}
	f->shape[n] = NULL;
}
