/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_malloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:40:22 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/02/19 16:40:23 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		free_fplace(t_filler *f)
{
	free(f->place[0]);
	free(f->place[1]);
	free(f->place[2]);
	free(f->place);
}

void		add_to_int_end(t_filler *f, int i, int size)
{
	f->place[0][0] = size;
	while (i < size)
	{
		f->place[1][i] = -999;
		f->place[2][i] = -999;
		i++;
	}
}

void		realloc_int_arr(t_filler *f, int flag)
{
	int		i;
	int		size;
	int		**ret;

	i = 0;
	ret = malloc(sizeof(int*) * 3);
	if (flag == 0)
		size = 10;
	else
		size = f->place[0][0] * 2;
	ret[0] = malloc(sizeof(int) * 1);
	ret[1] = malloc(sizeof(int) * size);
	ret[2] = malloc(sizeof(int) * size);
	if (flag == 1)
	{
		while (i < f->place[0][0])
		{
			ret[1][i] = f->place[1][i];
			ret[2][i] = f->place[2][i];
			i++;
		}
		free_fplace(f);
	}
	f->place = ret;
	add_to_int_end(f, i, size);
}

void		free_array(char **arr, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
