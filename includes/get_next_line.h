/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:30:27 by ssarkisi          #+#    #+#             */
/*   Updated: 2017/12/12 16:23:52 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"

# define BUFF_SIZE 42

typedef struct	s_gnl
{
	char			*buf;
	int				fd;
	struct s_gnl	*next;
}				t_gnl;

int				get_next_line(const int fd, char **line);
#endif
