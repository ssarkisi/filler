/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 20:09:01 by ycribier          #+#    #+#             */
/*   Updated: 2015/02/25 14:41:00 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <sys/types.h>
# include "libft.h"

typedef struct	s_filler
{
	int			mynum;
	char		ch;
	char		ch1;
	int			fx;
	int			fy;
	int			stpos[2];
	int			stpos1[2];
	int			stflag;
	int			px;
	int			py;
	char		**field;
	char		**piece;
	char		**shape;
	int			x_tost;
	int			y_tost;
	int			sx;
	int			sy;
	int			**place;
	int			goal[2];
	int			chpos[4];
	int			ch1pos[4];
}				t_filler;

void			write_xy(int y, int x, int fd);
void			set_xy_tost(t_filler *f);
void			set_goal(t_filler *f);
int				module(int n);
void			set_xy(t_filler *f, char *line, int i);
void			set_stpos(t_filler *f);
void			set_mynum(t_filler *f, char *line);
char			*cut_line(char *l);
void			set_field(t_filler *f, int fd);
void			set_piece(t_filler *f, int fd);
int				get_cut_start(char **ar);
int				get_cut_end(char **ar);
char			*get_shape_line(char *s, int start, int end);
void			cut_shape(t_filler *f);
void			best_place(t_filler *f, int i, int i1);
void			add_place(t_filler *f, int y, int x);
int				check_place(t_filler *f, int x, int y, int flag);
void			set_all_place(t_filler *f);
void			find_place(t_filler *f);
void			realloc_int_arr(t_filler *f, int flag);
void			free_array(char **arr, int size);
t_filler		*get_new_struct(void);
void			left_top_position_aloritm(t_filler *f);
void			right_down_position_aloritm(t_filler *f);
int				check_left(t_filler *f, char c);
int				check_right(t_filler *f, char c);
int				check_top(t_filler *f, char c);
int				check_down(t_filler *f, char c);
int				find_left(t_filler *f, char c);
int				find_right(t_filler *f, char c);
int				find_top(t_filler *f, char c);
int				find_down(t_filler *f, char c);
void			set_chpos(t_filler *f);

#endif
