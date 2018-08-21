/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:16:54 by ssarkisi          #+#    #+#             */
/*   Updated: 2018/02/19 16:16:55 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_filler	*get_new_struct(void)
{
	t_filler	*f;

	f = malloc(sizeof(t_filler));
	f->mynum = 0;
	f->ch = '\0';
	f->ch1 = '\0';
	f->fx = 0;
	f->fy = 0;
	f->stflag = 0;
	f->px = 0;
	f->py = 0;
	f->x_tost = 0;
	f->y_tost = 0;
	f->sx = 0;
	f->sy = 0;
	f->stpos[0] = 0;
	f->stpos[1] = 0;
	f->goal[0] = 0;
	f->goal[1] = 0;
	return (f);
}
