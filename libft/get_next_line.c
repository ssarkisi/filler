/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:30:06 by ssarkisi          #+#    #+#             */
/*   Updated: 2017/12/12 16:23:39 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	*check_fd(t_gnl *gnl, int fd)
{
	t_gnl	*tmp;
	t_gnl	*new;
	t_gnl	*head;

	head = gnl;
	while (gnl)
	{
		if (gnl->fd == fd)
			return (gnl);
		if (gnl->next && gnl->next->fd == fd)
		{
			tmp = gnl;
			gnl = gnl->next;
			tmp->next = tmp->next->next;
			gnl->next = head;
			return (gnl);
		}
		gnl = gnl->next;
	}
	new = malloc(sizeof(t_gnl));
	new->fd = fd;
	new->buf = NULL;
	new->next = head;
	return (new);
}

static int		check_n(char **line, char *buf)
{
	char	*tmp;

	tmp = ft_strchr(buf, '\n');
	if (tmp != NULL)
	{
		*line = ft_strsub(buf, 0, (tmp - buf));
		ft_memmove(buf, (tmp + 1), ft_strlen(tmp));
		tmp = NULL;
		return (1);
	}
	return (0);
}

static int		ft_read(char **line, char **buf, int const fd)
{
	int		ret;
	char	*s;
	char	s2[BUFF_SIZE + 1];

	while ((ret = read(fd, s2, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		s = NULL;
		s2[ret] = '\0';
		if (*buf != NULL)
		{
			s = ft_strdup(*buf);
			ft_memdel((void **)buf);
			*buf = ft_strjoin(s, s2);
			ft_memdel((void **)&s);
		}
		else
			*buf = ft_strdup(s2);
		if (check_n(line, *buf) == 1)
			return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	static t_gnl	*gnl;

	gnl = check_fd(gnl, fd);
	if (line == NULL || fd < 0 || read(fd, NULL, 0) < 0)
		return (-1);
	if (gnl->buf != NULL && check_n(line, gnl->buf) == 1)
		return (1);
	ret = ft_read(line, &gnl->buf, fd);
	if (ret != 0)
		return (ret);
	if (gnl->buf == NULL || gnl->buf[0] == '\0')
		return (0);
	*line = gnl->buf;
	gnl->buf = NULL;
	return (1);
}
